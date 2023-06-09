cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(publisher src/publisher.cpp)
ament_target_dependencies(publisher rclcpp std_msgs geometry_msgs)

add_executable(subscriber src/subscriber.cpp)
ament_target_dependencies(subscriber rclcpp std_msgs geometry_msgs)

install(TARGETS
  publisher
  subscriber
  DESTINATION lib/${PROJECT_NAME})

ament_package()
