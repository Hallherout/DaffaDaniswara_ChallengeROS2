cmake_minimum_required(VERSION 3.8)
project(controller_package)

# Pastikan compiler pakai C++14 ke atas
if(NOT CMAKE_CXX_STANDARD)
 set(CMAKE_CXX_STANDARD 14)
endif()

# Temukan dependency utama ROS2
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(package_messages REQUIRED)   # custom message package kamu
find_package(std_msgs REQUIRED)

# Tambahkan executable publisher
add_executable(controller_publisher src/controller_publisher.cpp)
ament_target_dependencies(controller_publisher
    rclcpp
    std_msgs
    package_messages
)

# Tambahkan executable subscriber
add_executable(controller_subscriber src/controller_subscriber.cpp)
ament_target_dependencies(controller_subscriber
    rclcpp
    std_msgs
    package_messages
)

# Install agar dikenali ros2 run
install(TARGETS
    controller_publisher
    controller_subscriber
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()