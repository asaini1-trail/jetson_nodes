#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import Float64


class RCMapper(Node):
    def __init__(self):
        super().__init__('rc_mapper')

        # Publishers
        self.pub_throttle = self.create_publisher(Float64, 'cmd_throttle', 10)
        self.pub_steering = self.create_publisher(Float64, 'cmd_steering', 10)

        # Subscriber to PS4 controller
        self.sub_joy = self.create_subscription(
            Joy,
            'joy',
            self.joy_callback,
            10
        )

        self.get_logger().info('RC mapper node started.')

    def joy_callback(self, msg: Joy):
        # Raw inputs from sticks
        raw_throttle = -msg.axes[1]      # invert so forward stick = positive
        raw_steering = msg.axes[3]

        # Clamp throttle to [0, 1]
        throttle = max(0.0, min(raw_throttle, 1.0))

        # Clamp steering to [-1, 1]
        steering = max(-1.0, min(raw_steering, 1.0))

        # Publish
        t_msg = Float64()
        t_msg.data = throttle

        s_msg = Float64()
        s_msg.data = steering

        self.pub_throttle.publish(t_msg)
        self.pub_steering.publish(s_msg)


def main(args=None):
    rclpy.init(args=args)
    node = RCMapper()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

