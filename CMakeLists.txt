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
        src/Operate/OperateBase.cpp
        src/Operate/OperateCreate.cpp
        src/Operate/Operate.cpp
        src/Operate/OperateInsert.cpp
        src/Function/CSV.cpp
        src/Function/String.cpp
        src/Function/Function.cpp
        src/Operate/OperateMess.cpp
        src/Operate/OperateMess.h
        include/easylogging++/easylogging++.cc
        src/CppDB.cpp
        src/Function/Logger.cpp
        src/Function/Logger.hpp
        src/Operate/OperateAlert.cpp
)

add_executable(mess test/mess.cpp
        src/Structure/Database.cpp
        src/Structure/Table.cpp
        src/Structure/Event.cpp
        src/Structure/SingleTable.cpp
        src/Operate/OperateBase.cpp
        src/Operate/OperateCreate.cpp
        src/Operate/Operate.cpp
        src/Operate/OperateInsert.cpp
        src/Function/CSV.cpp
        src/Function/String.cpp
        src/Function/Function.cpp
        src/Operate/OperateMess.cpp
        src/Operate/OperateMess.h
        include/easylogging++/easylogging++.cc
        src/CppDB.cpp
        src/Function/Logger.cpp
        src/Function/Logger.hpp
        src/Operate/OperateUpdate.cpp
        src/Operate/OperateUpdate.h
        src/Operate/OperateSelect.cpp
        src/Operate/OperateSelect.h
        src/Operate/OperateDelete.cpp
        src/Operate/OperateDelete.h
        src/Operate/OperateAlert.cpp
)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/target")
