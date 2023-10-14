cmake_minimum_required(VERSION 3.0.2)
project(ros_study_others)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  nav_msgs
  geometry_msgs
  tf2
)


###################################
## catkin specific configuration ##
###################################
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES ros_study_others
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)


###########
## Build ##
###########
## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(include ${catkin_INCLUDE_DIRS})
## Declare a C++ executable
add_executable(ros_study_others src/code1.cpp)
## Specify libraries to link a library or executable target against
target_link_libraries(ros_study_others ${catkin_LIBRARIES})
