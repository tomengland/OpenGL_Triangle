cmake_minimum_required(VERSION 4.0)
project(OpenGL_Triangle)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

# Add GLAD as a library
add_library(glad glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

add_executable(OpenGL_Triangle main.cpp)
target_link_libraries(OpenGL_Triangle glad glfw OpenGL::GL)