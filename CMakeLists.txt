cmake_minimum_required(VERSION 3.0.2)
set(PROJECT_NAME "test_data_node")
project(${PROJECT_NAME})


find_package(catkin REQUIRED COMPONENTS roscpp std_msgs message_generation)

## Generate messages in the 'msg' folder4
add_message_files(
  FILES
  SinWaves.msg
  TestData.msg
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)
catkin_package(
  CATKIN_DEPENDS roscpp message_generation message_runtime
)
include_directories(
# include
 ${CMAKE_SOURCE_DIR}/../../../third_party_libs/CKROSlibzmq/include
 ${CMAKE_SOURCE_DIR}/../../../third_party_libs/CKROSprotobuf/src
 ${CMAKE_SOURCE_DIR}/../../../third_party_libs/ROSProtoDef2022/out
 ${catkin_INCLUDE_DIRS}
)

message("CATKIN INCLUDES:${catkin_INCLUDE_DIRS}")

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(test_data_node src/test_data_node.cpp)
target_link_libraries(test_data_node ${catkin_LIBRARIES})
target_link_libraries(test_data_node Threads::Threads)
add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
