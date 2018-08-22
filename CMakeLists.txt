cmake_minimum_required(VERSION 3.10)
project(mmn-17-computer-graphics)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(imgui)
include_directories(${PROJECT_SOURCE_DIR})

find_package(OpenGL REQUIRED)
find_package(GLut REQUIRED)

add_executable(mmn17 main.cpp main.cpp dog.cpp dog.h items.cpp items.h)


target_link_libraries(mmn17 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} imgui)
