cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

project(chapter11)

add_executable(student1 lecture/student1.c)
add_executable(student2 lecture/student2.c)
add_executable(point lecture/point.c)
add_executable(nested_struct lecture/nested_struct.c)
