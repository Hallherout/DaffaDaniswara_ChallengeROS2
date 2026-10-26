cmake_minimum_required(VERSION 3.5)
project(package_messages)

# Temukan dependency utama
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Definisi file pesan
set(msg_files
    "msg/Controller.msg"
)

# Generate pesan
rosidl_generate_interfaces(${PROJECT_NAME}
    ${msg_files}
    DEPENDENCIES std_msgs
)

# Package configuration
ament_export_dependencies(rosidl_default_runtime)
ament_package()