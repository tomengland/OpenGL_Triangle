cmake_minimum_required(VERSION 4.0)
project(OpenGL_Triangle)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

add_subdirectory("C:/Users/Admin/Documents/Libraries/glfw-3.4" glfw)
find_package(OpenGL REQUIRED)

# Add GLAD as a library
add_library(glad glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

add_executable(OpenGL_Triangle src/main.cpp
        src/Shader.h)
target_link_libraries(OpenGL_Triangle glad glfw OpenGL::GL)