cmake_minimum_required(VERSION 3.5)

project(CppDB)

set(CMAKE_CXX_STANDARD 17)

message(STATUS ${CMAKE_BINARY_DIR})
message(STATUS ${CMAKE_SOURCE_DIR})

set(TEST_DIR ${CMAKE_SOURCE_DIR}/test/)

add_executable(test_all test/all.cpp
        src/Structure/Database.cpp
        src/Structure/Table.cpp
        src/Structure/Event.cpp
        src/Structure/SingleTable.cpp
        src/Operate/Operate.cpp
        src/Operate/OperateCreate.cpp
        src/Operate/OperateFactory.cpp
        src/Operate/OperateInsert.cpp
        src/Function/CSV.cpp
        src/Function/String.cpp
        src/Function/Function.cpp
        src/Operate/OperateMess.cpp
        src/Operate/OperateMess.hpp
        src/CppDB.cpp
)

add_executable(mess test/mess.cpp
        src/Structure/Database.cpp
        src/Structure/Table.cpp
        src/Structure/Event.cpp
        src/Structure/SingleTable.cpp
        src/Operate/Operate.cpp
        src/Operate/OperateCreate.cpp
        src/Operate/OperateFactory.cpp
        src/Operate/OperateInsert.cpp
        src/Function/CSV.cpp
        src/Function/String.cpp
        src/Function/Function.cpp
        src/Operate/OperateMess.cpp
        src/Operate/OperateMess.hpp
        src/CppDB.cpp
)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/target")
