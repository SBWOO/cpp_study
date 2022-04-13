cmake_minimum_required(VERSION 3.0)
project(gtest-tutorial)
set(CMAKE_CXX_STANDARD 14)

#find_package(gtest REQUIRED)

set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)
add_compile_options(-g -O0 -fprofile-arcs -ftest-coverage)
link_libraries(gcov)

set(TARGET_LIB sum)
add_library(${TARGET_LIB} SHARED sum.cpp)

set(TARGET_APP sum_app)
add_executable(${TARGET_APP} main.cpp)
target_include_directories(${TARGET_APP} PRIVATE .)
target_link_directories(${TARGET_APP} PRIVATE .)
target_link_libraries(${TARGET_APP} ${TARGET_LIB})

set(TARGET_TEST run_sum_tests)
add_executable(${TARGET_TEST} sum_test.cpp)
#target_include_directories(${TARGET_TEST} PRIVATE . usr/local/include)
#target_link_directories(${TARGET_TEST} PRIVATE . usr/local/lib/)

target_link_libraries(${TARGET_TEST} PRIVATE ${TARGET_LIB} gtest gtest_main pthread)

set(COVERAGE_REPORT_DIR coverage_report)
set(GCOV_FILE_DIR CMakeFiles/${TARGET_LIB}.dir/src)
add_custom_target(sumtest
                    COMMENT "Execute all unit test case and generate coverage report"
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                    DEPENDS ${TARGET_TEST}
                    COMMAND mkdir -p ${COVERAGE_REPORT_DIR}
                    COMMAND rm -rf ${COVERAGE_REPORT_DIR})
