cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop
    OOP.cpp
    File.h
    File.cpp
)

target_include_directories(oop PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/tabulate-master/include
)

