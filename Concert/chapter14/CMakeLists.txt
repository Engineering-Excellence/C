cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "-fexec-charset=UTF-8")

project(chapter14)

add_executable(malloc lecture/malloc.c)
add_executable(malloc1 lecture/malloc1.c)
add_executable(malloc2 lecture/malloc2.c)
add_executable(malloc3 lecture/malloc3.c)
add_executable(malloc4 lecture/malloc4.c)
add_executable(book1 lecture/book1.c)
add_executable(book2 lecture/book2.c)
add_executable(ex01 programming/ex01.c)
