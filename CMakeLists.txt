cmake_minimum_required(VERSION 3.20)

project(test LANGUAGES CXX)

if (NOT MSVC)
    message(FATAL_ERROR "need Microsoft CL complier")
endif()

add_executable(test msc.cpp)

