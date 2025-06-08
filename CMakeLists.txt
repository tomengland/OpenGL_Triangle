cmake_minimum_required(VERSION 3.16)

project(OpenGL_Triangle)
set(CMAKE_CXX_STANDARD 20)


add_subdirectory(C:/Libraries/glfw-3.4 ${CMAKE_BINARY_DIR}/glfw)
find_package(OpenGL REQUIRED)
# Add GLAD as a library
add_library(glad glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

add_executable(OpenGL_Triangle src/main.cpp
        src/shader.h)
target_compile_options(OpenGL_Triangle PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
)

target_link_libraries(OpenGL_Triangle glad glfw OpenGL::GL)