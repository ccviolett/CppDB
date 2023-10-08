cmake_minimum_required(VERSION 3.5)

project(CppDB)

set(CMAKE_CXX_STANDARD 17)

message(STATUS ${CMAKE_BINARY_DIR})
message(STATUS ${CMAKE_SOURCE_DIR})

set(TEST_DIR ${CMAKE_SOURCE_DIR}/test/)

aux_source_directory(${CMAKE_SOURCE_DIR}/src SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/Function FUNCTION_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/Operate OPERATE_LIST)

message(STATUS ${SRC_LIST})

add_executable(test_all ${TEST_DIR}/all.cpp ${SRC_LIST} ${FUNCTION_LIST} ${OPERATE_LIST}
        src/Function/Function.cpp
        src/CppDB.h)

# set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/target")
