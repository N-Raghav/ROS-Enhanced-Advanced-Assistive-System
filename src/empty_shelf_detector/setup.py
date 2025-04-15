from setuptools import find_packages, setup

package_name = 'empty_shelf_detector'

setup(
    name=package_name,
    version='0.1.0',  # Match with package.xml if possible
    packages=find_packages(exclude=['test']),  # Better exclusion handling
    data_files=[
        ('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Raghav',
    maintainer_email='raghavn753@gmail.com',
    description='A ROS 2 package to detect and alert for empty shelves using visual data.',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'esd = empty_shelf_detector.esd:main',
            'esd_subscriber = empty_shelf_detector.esd_subscriber:main',
        ],
    },
)
