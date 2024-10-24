cmake_minimum_required(VERSION 3.30.5)

set(This laborw7_2)

project(${This} C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers 
    labor7_2.hpp
)
set(Sources 
    labor7_2.cpp
)


add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)
