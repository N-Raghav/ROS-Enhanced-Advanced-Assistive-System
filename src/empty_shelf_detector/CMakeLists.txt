cmake_minimum_required(VERSION 3.5)
project(empty_shelf_detector)

# Required packages
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)  # Important for Python packaging
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(empty_shelf_msgs REQUIRED)

# Install Python modules
ament_python_install_package(${PROJECT_NAME})

# Install executables (if any in scripts/)
install(PROGRAMS
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
