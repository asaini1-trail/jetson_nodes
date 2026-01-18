from setuptools import setup

package_name = 'gridrover_teleop'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/teleop.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='abhijeet',
    maintainer_email='you@example.com',
    description='Teleop for GridRover using PS4 controller',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'rc_mapper = gridrover_teleop.rc_mapper:main',
            'gps_recorder = gridrover_teleop.gps_recorder:main',
        ],
    },
)

