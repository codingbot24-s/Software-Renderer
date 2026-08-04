cmake_minimum_required(VERSION 4.3)
project(c C)

set(CMAKE_C_STANDARD 11)

# Find the SDL3 package
find_package(SDL3 REQUIRED)


add_executable(c main.c
        sdl_init.h
        sdl_init.c
        draw.h
        draw.c
        constant.h)

target_link_libraries(c PRIVATE SDL3::SDL3)