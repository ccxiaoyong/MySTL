cmake_minimum_required(VERSION 3.16)
project(syvector)
add_compile_options(-std=c++11)
include_directories(${PROJECT_SOURCE_DIR})

add_executable(test 
    test.cpp 
)


