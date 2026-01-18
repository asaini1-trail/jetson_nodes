# PS4 Controller State Message
# Complete state of all PS4 DualShock 4 controller inputs
# with human-readable field names for easy identification

# Header with timestamp
std_msgs/Header header

# Left Stick (Analog)
float32 left_stick_x       # Left/Right: -1.0 (left) to +1.0 (right)
float32 left_stick_y       # Up/Down: -1.0 (down) to +1.0 (up)

# Right Stick (Analog)
float32 right_stick_x      # Left/Right: -1.0 (left) to +1.0 (right)
float32 right_stick_y      # Up/Down: -1.0 (down) to +1.0 (up)

# Triggers (Analog)
float32 l2_trigger         # L2 analog value: -1.0 (not pressed) to +1.0 (fully pressed)
float32 r2_trigger         # R2 analog value: -1.0 (not pressed) to +1.0 (fully pressed)

# D-Pad (Analog axes - some controllers report as buttons)
float32 dpad_x             # Left/Right: -1.0 (left), 0.0 (center), +1.0 (right)
float32 dpad_y             # Up/Down: -1.0 (down), 0.0 (center), +1.0 (up)

# Face Buttons (Boolean - Digital)
bool button_x              # X button (Square on PS4)
bool button_circle         # Circle button
bool button_triangle       # Triangle button
bool button_square         # Square button

# Shoulder Buttons (Boolean - Digital)
bool button_l1             # L1 shoulder button
bool button_r1             # R1 shoulder button

# Trigger Buttons (Boolean - Digital, some controllers have both analog and digital)
bool button_l2             # L2 trigger button (digital threshold)
bool button_r2             # R2 trigger button (digital threshold)

# Center Buttons (Boolean - Digital)
bool button_share          # Share button (Select on older controllers)
bool button_options        # Options button (Start on older controllers)
bool button_ps             # PS/Home button

# Stick Click Buttons (Boolean - Digital)
bool button_l3             # L3 button (left stick click)
bool button_r3             # R3 button (right stick click)

# D-Pad Buttons (Boolean - some controllers use buttons instead of axes)
bool dpad_up               # D-pad up
bool dpad_down             # D-pad down
bool dpad_left             # D-pad left
bool dpad_right            # D-pad right

# Touchpad (if available)
bool touchpad_pressed      # Touchpad button press

# Raw arrays for reference (matches sensor_msgs/Joy format)
float32[] axes_raw         # Raw axes array from joy_node
bool[] buttons_raw         # Raw buttons array from joy_node
