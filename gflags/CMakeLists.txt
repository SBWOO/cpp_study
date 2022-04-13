cmake_minimum_required(VERSION 3.0)

project(gflag_eg )
add_compile_options(-g)

find_package(gflags REQUIRED)
include_directories (${gflags_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} gflags)

#target_include_directories(${TARGET_TEST} PRIVATE . usr/local/include)
#target_link_directories(${TARGET_TEST} PRIVATE . usr/local/lib/)
