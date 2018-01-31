cmake_minimum_required(VERSION 3.7)
project(aisd_lab_rab)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(aisd_lab_rab ${SOURCE_FILES})

add_executable(test_table test_table.cpp)

add_executable(test_ksi test_ksi.cpp)