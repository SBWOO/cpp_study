project(Eigentutorial)
cmake_minimum_required(VERSION 3.5)
# Eigen
find_package(Eigen3 3.3 REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(HelloEigen helloeigen.cpp)
add_executable(EigenBlock eigen_block.cpp)
