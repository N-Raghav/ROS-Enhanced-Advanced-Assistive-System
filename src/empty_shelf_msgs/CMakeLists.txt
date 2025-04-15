cmake_minimum_required(VERSION 3.5)
project(empty_shelf_msgs)

find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/EmptyShelfAlert.msg"
  DEPENDENCIES std_msgs geometry_msgs builtin_interfaces
)

ament_export_dependencies(rosidl_default_runtime)

# Optional - install .msg files (useful for introspection/IDE support)
install(DIRECTORY msg
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
