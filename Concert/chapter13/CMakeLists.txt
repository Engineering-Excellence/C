cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 14)

project(chapter13)

add_executable(macro1 lecture/macro1.c)
add_executable(macro2 lecture/macro2.c)
add_executable(macro3 lecture/macro3.c)
add_executable(macro5 lecture/macro5.c)
add_executable(power lecture/power.c lecture/main.c)
add_executable(mainarg lecture/mainarg.c)
add_executable(mile2km lecture/mile2km.c)
