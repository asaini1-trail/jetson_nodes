#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from std_msgs.msg import Bool, Int32, Float32, Float32MultiArray
import csv
import os
from datetime import datetime


class GPSRecorder(Node):
    def __init__(self):
        super().__init__('gps_recorder')

        # Recording state
        self.is_recording = False
        self.csv_file = None
        self.csv_writer = None
        self.csv_filename = None
        self.point_counter = 0

        # Latest values from all topics (stored until GPS callback writes them)
        self.latest_gps = None
        self.latest_decay_mode = None
        self.latest_front_distance = None
        self.latest_throttle_regulated = None
        self.latest_left_stick_y = None
        self.latest_right_stick_x = None
        self.latest_vesc_status = None
        self.latest_vesc_voltage_avg = None
        self.latest_vesc_voltage_one = None
        self.latest_vesc_voltages = None

        # Subscribe to GPS fix topic (main trigger for recording)
        self.sub_gps = self.create_subscription(
            NavSatFix,
            '/gps/fix',
            self.gps_callback,
            10
        )

        # Subscribe to L2 button toggle topic
        self.sub_l2 = self.create_subscription(
            Bool,
            '/ps4/button_l2',
            self.l2_callback,
            10
        )

        # Subscribe to decay mode
        self.sub_decay_mode = self.create_subscription(
            Int32,
            '/decay_mode',
            lambda msg: setattr(self, 'latest_decay_mode', msg.data),
            10
        )

        # Subscribe to front distance
        self.sub_front_distance = self.create_subscription(
            Float32,
            '/front_distance',
            lambda msg: setattr(self, 'latest_front_distance', msg.data),
            10
        )

        # Subscribe to throttle regulated
        self.sub_throttle_regulated = self.create_subscription(
            Int32,
            '/throttel_regulated',
            lambda msg: setattr(self, 'latest_throttle_regulated', msg.data),
            10
        )

        # Subscribe to PS4 left stick Y (throttle)
        self.sub_left_stick_y = self.create_subscription(
            Float32,
            '/ps4/left_stick_y',
            lambda msg: setattr(self, 'latest_left_stick_y', msg.data),
            10
        )

        # Subscribe to PS4 right stick X (steering)
        self.sub_right_stick_x = self.create_subscription(
            Float32,
            '/ps4/right_stick_x',
            lambda msg: setattr(self, 'latest_right_stick_x', msg.data),
            10
        )

        # Subscribe to VESC telemetry topics
        self.sub_vesc_status = self.create_subscription(
            Int32,
            '/vesc/telemetry/status',
            lambda msg: setattr(self, 'latest_vesc_status', msg.data),
            10
        )

        self.sub_vesc_voltage_avg = self.create_subscription(
            Float32,
            '/vesc/telemetry/voltage/average',
            lambda msg: setattr(self, 'latest_vesc_voltage_avg', msg.data),
            10
        )

        self.sub_vesc_voltage_one = self.create_subscription(
            Float32,
            '/vesc/telemetry/voltage_one',
            lambda msg: setattr(self, 'latest_vesc_voltage_one', msg.data),
            10
        )

        self.sub_vesc_voltages = self.create_subscription(
            Float32MultiArray,
            '/vesc/telemetry/voltages',
            self.vesc_voltages_callback,
            10
        )

        # Create directory for GPS logs if it doesn't exist
        self.log_dir = os.path.expanduser('~/gps_logs')
        os.makedirs(self.log_dir, exist_ok=True)

        self.get_logger().info('GPS Recorder node started.')
        self.get_logger().info(f'GPS logs will be saved to: {self.log_dir}')
        self.get_logger().info('Press L2 button to start/stop recording.')

    def vesc_voltages_callback(self, msg: Float32MultiArray):
        """Store VESC voltages array as comma-separated string"""
        if msg.data:
            self.latest_vesc_voltages = ','.join([f'{v:.2f}' for v in msg.data])
        else:
            self.latest_vesc_voltages = ''

    def l2_callback(self, msg: Bool):
        """Handle L2 button toggle - start/stop recording"""
        if msg.data and not self.is_recording:
            # Start recording
            self.start_recording()
        elif not msg.data and self.is_recording:
            # Stop recording
            self.stop_recording()

    def start_recording(self):
        """Start recording GPS coordinates and telemetry to CSV"""
        # Generate filename with timestamp
        timestamp = datetime.now().strftime('%Y%m%d_%H%M%S')
        self.csv_filename = os.path.join(self.log_dir, f'gps_track_{timestamp}.csv')

        try:
            # Open CSV file for writing
            self.csv_file = open(self.csv_filename, 'w', newline='')
            self.csv_writer = csv.writer(self.csv_file)

            # Write header with all fields
            self.csv_writer.writerow([
                'point_id',
                'timestamp',
                'latitude',
                'longitude',
                'altitude',
                'gps_status',
                'position_covariance_type',
                'decay_mode',
                'front_distance',
                'throttle_regulated',
                'left_stick_y',
                'right_stick_x',
                'vesc_status',
                'vesc_voltage_avg',
                'vesc_voltage_one',
                'vesc_voltages'
            ])

            self.is_recording = True
            self.point_counter = 0

            self.get_logger().info(f'Started GPS recording: {self.csv_filename}')

        except Exception as e:
            self.get_logger().error(f'Failed to start recording: {str(e)}')
            if self.csv_file:
                self.csv_file.close()
                self.csv_file = None

    def stop_recording(self):
        """Stop recording GPS coordinates"""
        if self.csv_file:
            self.csv_file.close()
            self.csv_file = None
            self.csv_writer = None

            self.get_logger().info(f'Stopped GPS recording. Saved {self.point_counter} points to: {self.csv_filename}')

        self.is_recording = False
        self.point_counter = 0

    def gps_callback(self, msg: NavSatFix):
        """Record GPS data and all telemetry when recording is active"""
        if not self.is_recording or not self.csv_writer:
            return

        try:
            # Get current timestamp
            timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S.%f')[:-3]

            # Increment point counter
            self.point_counter += 1

            # Write GPS data and all telemetry to CSV
            self.csv_writer.writerow([
                self.point_counter,
                timestamp,
                msg.latitude,
                msg.longitude,
                msg.altitude,
                msg.status.status,
                msg.position_covariance_type,
                self.latest_decay_mode if self.latest_decay_mode is not None else '',
                self.latest_front_distance if self.latest_front_distance is not None else '',
                self.latest_throttle_regulated if self.latest_throttle_regulated is not None else '',
                self.latest_left_stick_y if self.latest_left_stick_y is not None else '',
                self.latest_right_stick_x if self.latest_right_stick_x is not None else '',
                self.latest_vesc_status if self.latest_vesc_status is not None else '',
                self.latest_vesc_voltage_avg if self.latest_vesc_voltage_avg is not None else '',
                self.latest_vesc_voltage_one if self.latest_vesc_voltage_one is not None else '',
                self.latest_vesc_voltages if self.latest_vesc_voltages is not None else ''
            ])

            # Flush to ensure data is written
            self.csv_file.flush()

            # Log every 10 points to avoid spam
            if self.point_counter % 10 == 0:
                self.get_logger().info(
                    f'Recorded point {self.point_counter}: '
                    f'Lat={msg.latitude:.6f}, Lon={msg.longitude:.6f}, '
                    f'Throttle={self.latest_left_stick_y:.2f if self.latest_left_stick_y is not None else "N/A"}, '
                    f'Dist={self.latest_front_distance:.2f if self.latest_front_distance is not None else "N/A"}m'
                )

        except Exception as e:
            self.get_logger().error(f'Error recording GPS data: {str(e)}')

    def __del__(self):
        """Cleanup when node is destroyed"""
        if self.csv_file:
            self.csv_file.close()


def main(args=None):
    rclpy.init(args=args)
    node = GPSRecorder()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        # Ensure file is closed on shutdown
        if node.csv_file:
            node.csv_file.close()
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
