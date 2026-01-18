from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        # PS4 controller -> /joy
        Node(
            package='joy',
            executable='joy_node',
            name='joy_node',
            output='screen',
            parameters=[{
                'dev': '/dev/input/js0',
                'deadzone': 0.05,
                'autorepeat_rate': 20.0,
                'coalesce_interval_ms': 1,
            }]
        ),

        # /joy -> /cmd_throttle, /cmd_steering
        Node(
            package='gridrover_teleop',
            executable='rc_mapper',
            name='rc_mapper',
            output='screen'
        ),

        # GPS recorder - records GPS coordinates to CSV when L2 is pressed
        Node(
            package='gridrover_teleop',
            executable='gps_recorder',
            name='gps_recorder',
            output='screen'
        ),
    ])

