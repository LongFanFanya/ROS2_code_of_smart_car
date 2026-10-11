cmake_minimum_required(VERSION 3.20)

project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

#装载cpp-node
add_executable(
  cpp_node
  src/my_first_node.cpp
)
#链接cpp_node所需要的库
target_link_libraries(cpp_node PRIVATE
  rclcpp::rclcpp
)


#装载robot_news_station
add_executable(
  robot_news_station
  src/robot_news_station.cpp
)

target_link_libraries(robot_news_station PRIVATE
  rclcpp::rclcpp
  ${example_interfaces_TARGETS}
)

#装载smartphone
add_executable(
  smartphone
  src/smartphone.cpp
)

target_link_libraries(smartphone PRIVATE
  rclcpp::rclcpp
  ${example_interfaces_TARGETS}
)


#装载add_two_ints_server
add_executable(
  add_two_ints_server
  src/add_two_ints_server.cpp
)

target_link_libraries(add_two_ints_server PRIVATE
  rclcpp::rclcpp
  ${example_interfaces_TARGETS}
)

#装载add_two_ints_client
add_executable(
  add_two_ints_client
  src/add_two_ints_client.cpp
)

target_link_libraries(add_two_ints_client PRIVATE
  rclcpp::rclcpp
  ${example_interfaces_TARGETS}
)


install(TARGETS
  cpp_node
  robot_news_station
  smartphone
  add_two_ints_server
  add_two_ints_client
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()