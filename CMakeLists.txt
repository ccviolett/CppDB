cmake_minimum_required(VERSION 2.8)

project(CppDB)

set(CMAKE_CXX_STANDARD 17)

message(STATUS ${CMAKE_BINARY_DIR})
message(STATUS ${CMAKE_SOURCE_DIR})

set(TEST_DIR ${CMAKE_SOURCE_DIR}/test/)

aux_source_directory(${CMAKE_SOURCE_DIR}/src/ SRC_LIST)

message(STATUS ${MAIN_LIST})
message(STATUS ${TEST_LIST})

add_executable(test_all ${TEST_DIR}/all.cpp ${SRC_LIST})

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/target")
