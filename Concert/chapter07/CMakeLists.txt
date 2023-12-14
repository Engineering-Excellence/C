cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

project(chapter07)

add_executable(square lecture/square.c)
add_executable(get_max lecture/get_max.c)
add_executable(combination lecture/combination.c)
add_executable(compute_sum lecture/compute_sum.c)
add_executable(static lecture/static.c)
add_executable(linkage lecture/linkage1.c lecture/linkage2.c)
add_executable(factorial lecture/factorial.c)
