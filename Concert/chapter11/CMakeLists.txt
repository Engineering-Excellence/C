cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

project(chapter11)

add_executable(student1 lecture/student1.c)
add_executable(student2 lecture/student2.c)
add_executable(point lecture/point.c)
add_executable(nested_struct lecture/nested_struct.c)
add_executable(array_of_struct lecture/array_of_struct.c)
add_executable(pointer_to_st lecture/pointer_to_st.c)
add_executable(st_pointer lecture/st_pointer.c)
