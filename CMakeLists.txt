set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_minimum_required(VERSION 3.7)

project(cmdArgsCpp)

set(sources
    src/src.cpp)

add_executable(cmdArgsCpp ${sources})

