cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

project(chapter06)

add_executable(gugu lecture/gugu.c)
add_executable(sum lecture/sum.c)
add_executable(average lecture/average.c)
add_executable(gcd lecture/gcd.c)
