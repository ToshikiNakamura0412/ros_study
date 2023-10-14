cmake_minimum_required(VERSION 3.0.2)
project(ros_study)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  nav_msgs
  geometry_msgs
  tf2
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ros_study_others
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(code1 src/others/code1.cpp)
target_link_libraries(code1 ${catkin_LIBRARIES})

add_executable(set_vel src/tools/set_vel_node.cpp)
target_link_libraries(set_vel ${catkin_LIBRARIES})
