cmake_minimum_required( VERSION 2.8)
project(dispatcher_demo)
add_compile_options(-pthread -g)

find_package(Threads)
include_directories("include")
add_library(dispatcher SHARED dispatcher.cpp request.cpp worker.cpp)
target_link_libraries(dispatcher Threads::Threads)


add_executable(${CMAKE_PROJECT_NAME} pipeline_main.cpp )
target_link_libraries(${CMAKE_PROJECT_NAME} dispatcher Threads::Threads)
