cmake_minimum_required(VERSION 3.10)
project(OpenGL-Compat-Game)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(game main.c)
# link_directories(/usr/lib/x86_64-linux-gnu)
target_link_libraries(game OpenGL::GL /usr/lib/x86_64-linux-gnu/libglfw.so)
