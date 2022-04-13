cmake_minimum_required(VERSION 2.6)
project(example CXX C)

find_package(GTSAM REQUIRED)
find_package(Eigen3 3.3 REQUIRED)
include_directories(${GTSAM_INCLUDE_DIR})
include_directories(${EIGEN_INCLUDE_DIR})

add_executable(tutorial_gtsam easyPoint2KalmanFilter.cpp)
target_link_libraries(tutorial_gtsam gtsam Eigen3)
