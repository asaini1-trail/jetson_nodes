#!/usr/bin/env python3
import rclpy
import time
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import Float32, Bool, Int32


class RCMapper(Node):
    def __init__(self):
        super().__init__('rc_mapper')

        # Publishers for driving commands - using PS4 stick names for clarity
        self.pub_throttle = self.create_publisher(Float32, '/ps4/left_stick_y', 10)  # Throttle (forward/backward)
        self.pub_steering = self.create_publisher(Float32, '/ps4/right_stick_x', 10)  # Steering (left/right)
        self.pub_pulse_width = self.create_publisher(Int32, 'headlamp_pwm', 10)

        # Individual button publishers - Only L1/L2/R1/R2 with toggle behavior
        self.pub_btn_l1 = self.create_publisher(Bool, '/ps4/button_l1', 10)
        self.pub_btn_r1 = self.create_publisher(Bool, '/ps4/button_r1', 10)
        self.pub_btn_l2 = self.create_publisher(Bool, '/ps4/button_l2', 10)
        self.pub_btn_r2 = self.create_publisher(Bool, '/ps4/button_r2', 10)

        # D-pad incremental value publishers (Float32 -1 to 1)
        self.pub_dpad_horizontal = self.create_publisher(Float32, '/ps4/dpad_horizontal', 10)
        self.pub_dpad_vertical = self.create_publisher(Float32, '/ps4/dpad_vertical', 10)

        # Subscribe to PS4 controller via joy_node
        self.sub_joy = self.create_subscription(
            Joy,
            'joy',
            self.joy_callback,
            10
        )
        
        # Subscribe to led_state topic to stop cycling when it becomes 1300
        self.sub_led_state = self.create_subscription(
            Int32,
            '/led_state',
            self.led_state_callback,
            10
        )

        # Button state tracking for toggle behavior
        # PS4 controller button indices: L1 = buttons[4], R1 = buttons[5]
        self.prev_l1_state = False
        self.prev_r1_state = False
        self.prev_l2_state = False
        self.prev_r2_state = False

        # D-pad state tracking for incremental changes
        self.prev_dpad_up = False
        self.prev_dpad_down = False
        self.prev_dpad_left = False
        self.prev_dpad_right = False

        # Current toggle states for L1/L2/R1/R2 (0 or 1)
        self.l1_toggle_state = 0
        self.l2_toggle_state = 0
        self.r1_toggle_state = 0
        self.r2_toggle_state = 0

        # D-pad incremental values (-1 to 1)
        self.dpad_horizontal_value = 0.0  # Left (-1) to Right (1)
        self.dpad_vertical_value = 0.0    # Down (-1) to Up (1)
        self.dpad_increment = 0.1  # Amount to change per press

        # Pulse width state (500-2500ms, default center at 1500ms)
        # Changes by 500ms increments with each D-pad press
        self.current_pulse_width = 1500.0  # ms
        self.pulse_width_step = 500.0  # ms per press
        
        # Headlamp PWM cycling state
        self.cycling_enabled = True  # Start cycling by default (when led_state not available)
        self.cycling_direction = 1  # 1 = increasing, -1 = decreasing
        self.led_state_received = False  # Track if led_state has been received
        self.led_state_last_time = None  # Track when led_state was last received
        self.led_state_value = None  # Current led_state value (None = not available)
        # Start cycling from 500ms
        self.current_pulse_width = 500.0  # Start at minimum for cycling
        self.target_pulse_width = 1500.0  # Target for smooth slew rate (500-1500 when led_state not available)
        self.slew_rate = 50.0  # Maximum change per cycle (ms) for smooth transitions (increased for faster cycling)
        self.cycling_timer_period = 0.1  # 100ms period for faster cycling
        self.led_state_timeout = 2.0  # Consider led_state unavailable if no message for 2 seconds
        
        # Timer for cycling PWM value (slower when led_state not available)
        self.cycling_timer = self.create_timer(self.cycling_timer_period, self.cycling_callback)
        
        # Timer to check if led_state topic is stale/not available
        self.led_state_check_timer = self.create_timer(1.0, self.check_led_state_availability)  # Check every 1 second
        
        # Debug flag to log controller info once
        self.debug_controller_info = True

        self.get_logger().info('RC mapper node started.')

    def publish_individual_buttons(self, msg: Joy):
        """Publish selected buttons and axes as individual topics"""

        # Helper function to safely get button value
        def get_button(index):
            return bool(msg.buttons[index]) if len(msg.buttons) > index else False

        # Helper function to safely get axis value
        def get_axis(index, default=0.0):
            return msg.axes[index] if len(msg.axes) > index else default

        # Handle L1/L2/R1/R2 with toggle behavior (0→1→0 on each press)
        current_l1 = get_button(4)
        current_r1 = get_button(5)
        current_l2 = get_button(6)
        current_r2 = get_button(7)

        # Toggle L1 state on rising edge
        if current_l1 and not self.prev_l1_state:
            self.l1_toggle_state = 1 if self.l1_toggle_state == 0 else 0
            self.get_logger().info(f'L1 toggled to {self.l1_toggle_state}')

        # Toggle R1 state on rising edge
        if current_r1 and not self.prev_r1_state:
            self.r1_toggle_state = 1 if self.r1_toggle_state == 0 else 0
            self.get_logger().info(f'R1 toggled to {self.r1_toggle_state}')

        # Toggle L2 state on rising edge
        if current_l2 and not self.prev_l2_state:
            self.l2_toggle_state = 1 if self.l2_toggle_state == 0 else 0
            self.get_logger().info(f'L2 toggled to {self.l2_toggle_state}')

        # Toggle R2 state on rising edge
        if current_r2 and not self.prev_r2_state:
            self.r2_toggle_state = 1 if self.r2_toggle_state == 0 else 0
            self.get_logger().info(f'R2 toggled to {self.r2_toggle_state}')

        # Update previous states
        self.prev_l1_state = current_l1
        self.prev_r1_state = current_r1
        self.prev_l2_state = current_l2
        self.prev_r2_state = current_r2

        # Publish shoulder buttons with toggle state
        self.pub_btn_l1.publish(Bool(data=(self.l1_toggle_state == 1)))
        self.pub_btn_r1.publish(Bool(data=(self.r1_toggle_state == 1)))
        self.pub_btn_l2.publish(Bool(data=(self.l2_toggle_state == 1)))
        self.pub_btn_r2.publish(Bool(data=(self.r2_toggle_state == 1)))

        # Handle D-pad with incremental values (-1 to 1)
        dpad_y_axis = get_axis(7, 0.0)
        dpad_x_axis = get_axis(6, 0.0)

        # Detect D-pad button presses
        dpad_up_pressed = (dpad_y_axis < -0.5) or get_button(13)
        dpad_down_pressed = (dpad_y_axis > 0.5) or get_button(14)
        dpad_left_pressed = (dpad_x_axis < -0.5) or get_button(15)
        dpad_right_pressed = (dpad_x_axis > 0.5) or get_button(16)

        # Increment/decrement values on button press (rising edge)
        if dpad_up_pressed and not self.prev_dpad_up:
            self.dpad_vertical_value = min(1.0, self.dpad_vertical_value + self.dpad_increment)
            self.get_logger().info(f'D-pad UP: vertical = {self.dpad_vertical_value:.2f}')

        if dpad_down_pressed and not self.prev_dpad_down:
            self.dpad_vertical_value = max(-1.0, self.dpad_vertical_value - self.dpad_increment)
            self.get_logger().info(f'D-pad DOWN: vertical = {self.dpad_vertical_value:.2f}')

        if dpad_left_pressed and not self.prev_dpad_left:
            self.dpad_horizontal_value = max(-1.0, self.dpad_horizontal_value - self.dpad_increment)
            self.get_logger().info(f'D-pad LEFT: horizontal = {self.dpad_horizontal_value:.2f}')

        if dpad_right_pressed and not self.prev_dpad_right:
            self.dpad_horizontal_value = min(1.0, self.dpad_horizontal_value + self.dpad_increment)
            self.get_logger().info(f'D-pad RIGHT: horizontal = {self.dpad_horizontal_value:.2f}')

        # Update previous D-pad states
        self.prev_dpad_up = dpad_up_pressed
        self.prev_dpad_down = dpad_down_pressed
        self.prev_dpad_left = dpad_left_pressed
        self.prev_dpad_right = dpad_right_pressed

        # Publish D-pad incremental values (Float32 -1 to 1)
        self.pub_dpad_horizontal.publish(Float32(data=self.dpad_horizontal_value))
        self.pub_dpad_vertical.publish(Float32(data=self.dpad_vertical_value))

    def joy_callback(self, msg: Joy):
        # AXIS MAPPING (DS4 + joy_node, safe choice):
        #   throttle: left stick vertical  -> axes[1]
        #   steering: left stick horizontal -> axes[0]
        #
        # Desired behavior:
        #   throttle:  0 at center
        #              +1 when stick pushed forward
        #              -1 when pulled backward
        #
        #   steering: -1 full left, +1 full right
        #
        # BUTTON MAPPING:
        #   L1/L2/R1/R2: Toggle buttons (published as /ps4/button_*)
        #   D-pad: Incremental values (published as /ps4/dpad_horizontal and /ps4/dpad_vertical)
        #   D-pad up/down (axes[7] or buttons[11]/[12]): Also controls headlamp PWM 500-2500ms
        #     Up = +500ms per press, Down = -500ms per press (incremental)

        if len(msg.axes) < 2:
            # something's wrong, don't spam logs
            return
        
        # Debug: log controller axes/buttons info once
        if self.debug_controller_info:
            self.get_logger().info(f'Controller info: {len(msg.axes)} axes, {len(msg.buttons)} buttons')
            if len(msg.axes) > 6:
                axes7_val = f'{msg.axes[7]:.3f}' if len(msg.axes) > 7 else 'N/A'
                self.get_logger().info(f'  axes[6] = {msg.axes[6]:.3f}, axes[7] = {axes7_val}')
            if len(msg.buttons) > 12:
                self.get_logger().info(f'  buttons[11] = {msg.buttons[11]}, buttons[12] = {msg.buttons[12]}')
            self.debug_controller_info = False

        raw_throttle = msg.axes[1]   # forward should be +1, back -1 (on your pad)
        raw_steering = msg.axes[2]   # left/right

        # Clamp both to [-1, 1]
        throttle = max(-1.0, min(raw_throttle, 1.0))
        steering = max(-1.0, min(raw_steering, 1.0))

        t_msg = Float32()
        t_msg.data = throttle

        s_msg = Float32()
        s_msg.data = steering

        self.pub_throttle.publish(t_msg)
        self.pub_steering.publish(s_msg)

        # Publish individual button topics
        self.publish_individual_buttons(msg)

        # Handle D-pad up/down for pulse width control (500-2500ms, 500ms steps)
        # D-pad mapping varies by controller/joy_node:
        #   Try multiple axis indices: axes[6] (horizontal), axes[7] (vertical)
        #   Or buttons[11] = up, buttons[12] = down
        # Increment/decrement by 500ms on each press (edge detection with debouncing)
        
        dpad_up_pressed = False
        dpad_down_pressed = False
        
        # Try multiple axis indices - D-pad can be on different axes depending on controller
        # axes[6] is often horizontal, axes[7] is often vertical
        if len(msg.axes) > 7:
            # Try axes[7] first (common D-pad vertical axis mapping)
            dpad_vertical = msg.axes[7]
            # Common mapping: up = -1.0, down = 1.0
            # Use threshold (0.5) to make it responsive
            if abs(dpad_vertical) > 0.5:  # Dead zone threshold
                if dpad_vertical < -0.5:  # Up pressed (assuming up = -1.0)
                    dpad_up_pressed = True
                elif dpad_vertical > 0.5:  # Down pressed (assuming down = 1.0)
                    dpad_down_pressed = True
        elif len(msg.axes) > 6:
            # Fallback: try axes[6] (sometimes D-pad is on this axis)
            dpad_vertical = msg.axes[6]
            if abs(dpad_vertical) > 0.5:
                if dpad_vertical < -0.5:
                    dpad_up_pressed = True
                elif dpad_vertical > 0.5:
                    dpad_down_pressed = True
        
        # Also try button mapping (buttons[11] = up, buttons[12] = down)
        if not dpad_up_pressed and not dpad_down_pressed and len(msg.buttons) > 12:
            dpad_up_pressed = bool(msg.buttons[11]) if len(msg.buttons) > 11 else False
            dpad_down_pressed = bool(msg.buttons[12]) if len(msg.buttons) > 12 else False
        
        # Handle incremental changes on button press (edge detection)
        # Only allow D-pad control when cycling is disabled (led_state has any value)
        if not self.cycling_enabled:
            value_changed = False
            if dpad_up_pressed and not self.prev_dpad_up:
                # D-pad up just pressed - increment by 500ms
                old_value = self.current_pulse_width
                self.current_pulse_width = min(2500.0, self.current_pulse_width + self.pulse_width_step)
                if old_value != self.current_pulse_width:
                    value_changed = True
                    self.get_logger().info(f'D-pad Up pressed: Headlamp PWM = {self.current_pulse_width:.0f}ms (was {old_value:.0f}ms)')
            
            if dpad_down_pressed and not self.prev_dpad_down:
                # D-pad down just pressed - decrement by 500ms
                old_value = self.current_pulse_width
                self.current_pulse_width = max(500.0, self.current_pulse_width - self.pulse_width_step)
                if old_value != self.current_pulse_width:
                    value_changed = True
                    self.get_logger().info(f'D-pad Down pressed: Headlamp PWM = {self.current_pulse_width:.0f}ms (was {old_value:.0f}ms)')
            
            # Update previous states
            self.prev_dpad_up = dpad_up_pressed
            self.prev_dpad_down = dpad_down_pressed
            
            # Always publish current pulse width value when D-pad control is active
            # This maintains the value and prevents fluctuations from cycling callback
            pw_msg = Int32()
            pw_msg.data = int(self.current_pulse_width)
            self.pub_pulse_width.publish(pw_msg)
            
            # Log if D-pad is being pressed but not changing (for debugging)
            if (dpad_up_pressed or dpad_down_pressed) and not value_changed:
                self.get_logger().debug(f'D-pad pressed but value unchanged (cycling_enabled={self.cycling_enabled}, current={self.current_pulse_width:.0f}ms)')
        else:
            # Update previous states even when cycling (to prevent false triggers when cycling stops)
            self.prev_dpad_up = dpad_up_pressed
            self.prev_dpad_down = dpad_down_pressed
    
    def led_state_callback(self, msg: Int32):
        """Callback for led_state topic - when any value received, stop cycling and enable D-pad control"""
        self.led_state_received = True
        self.led_state_last_time = time.time()
        self.led_state_value = msg.data
        
        # When led_state has any value, stop cycling and enable D-pad control
        if self.cycling_enabled:
            self.cycling_enabled = False
            self.get_logger().info(f'LED state received (value={msg.data}) - stopping headlamp PWM cycling, enabling D-pad control')
    
    def check_led_state_availability(self):
        """Check if led_state topic is available - if not, enable slow cycling"""
        current_time = time.time()
        
        # Check if led_state is unavailable (never received or stale)
        if not self.led_state_received or \
           (self.led_state_last_time is not None and 
            current_time - self.led_state_last_time > self.led_state_timeout):
            # Topic not available or stale, enable slow cycling
            if not self.cycling_enabled:
                self.cycling_enabled = True
                self.target_pulse_width = 1500.0  # Cycle between 500-1500
                self.current_pulse_width = 500.0
                self.cycling_direction = 1
                self.get_logger().info('LED state topic not available - starting slow headlamp PWM cycling (500-1500ms)')
        else:
            # Topic is available, ensure cycling is disabled
            if self.cycling_enabled:
                self.cycling_enabled = False
                # Don't change current_pulse_width when stopping - keep it at current value
                # This prevents blinking when transitioning from cycling to D-pad control
                self.get_logger().info(f'LED state topic available - stopping cycling at {self.current_pulse_width:.0f}ms, enabling D-pad control')
    
    def cycling_callback(self):
        """Timer callback to cycle headlamp PWM smoothly - 500-1500ms when led_state not available"""
        if not self.cycling_enabled:
            return  # Don't cycle if disabled - D-pad control is active
        
        # Update target based on direction (500-1500ms range when led_state not available)
        if self.cycling_direction > 0:
            self.target_pulse_width = 1500.0  # Target maximum
        else:
            self.target_pulse_width = 500.0  # Target minimum
        
        # Calculate difference to target
        diff = self.target_pulse_width - self.current_pulse_width
        
        # Apply slew rate for smooth transitions
        if abs(diff) > self.slew_rate:
            # Limit the change to slew_rate
            change = self.slew_rate if diff > 0 else -self.slew_rate
            self.current_pulse_width += change
        else:
            # Close to target, move directly to target
            self.current_pulse_width = self.target_pulse_width
            # Reverse direction when target is reached (with small threshold to avoid oscillation)
            if abs(diff) < 5.0:  # Close enough to target (increased threshold to prevent rapid switching)
                if self.cycling_direction > 0:
                    self.cycling_direction = -1  # Start decreasing
                    self.get_logger().debug(f'Headlamp PWM reached max (1500ms), reversing direction')
                else:
                    self.cycling_direction = 1  # Start increasing
                    self.get_logger().debug(f'Headlamp PWM reached min (500ms), reversing direction')
        
        # Clamp to valid range (500-1500ms when cycling)
        self.current_pulse_width = max(500.0, min(1500.0, self.current_pulse_width))
        
        # Publish the cycling value
        pw_msg = Int32()
        pw_msg.data = int(self.current_pulse_width)
        self.pub_pulse_width.publish(pw_msg)


def main(args=None):
    rclpy.init(args=args)
    node = RCMapper()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

