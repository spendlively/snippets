cmake_minimum_required(VERSION 2.8.9)

project(hello)

SET(CMAKE_CXX_FLAGS "-std=c++98")

add_executable(hello main.cpp sum.cpp)
