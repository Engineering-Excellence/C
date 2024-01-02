cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

project(chapter12)

add_executable(fw lecture/fw.c)
add_executable(precision lecture/precision.c)
add_executable(flag lecture/flag.c)
add_executable(printf_real lecture/printf_real.c)
