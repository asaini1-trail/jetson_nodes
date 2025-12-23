from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        # PS4 controller -> /joy
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            output='screen'
        ),

        # /joy -> /cmd_throttle, /cmd_steering
        Node(
            package='gridrover_teleop',
            executable='rc_mapper',
            name='rc_mapper',
            output='screen'
        ),
    ])

