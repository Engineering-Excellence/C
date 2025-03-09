cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=UTF-8")

project(Test)

add_executable(pl34 test/pl34.c)
add_executable(pl40 test/pl40.c)
