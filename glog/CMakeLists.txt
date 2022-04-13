project(glog_tutorial)
cmake_minimum_required(VERSION 3.0)

find_package(glog REQUIRED)
find_package(gflags REQUIRED)
include_directories (${glog_INCLUDE_DIR})

add_executable(glog_tutorial.out glog_tutorial.cpp)
target_link_libraries(glog_tutorial.out glog gflags)

