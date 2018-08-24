cmake_minimum_required(VERSION 3.10)
project(mmn-17-computer-graphics)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(imgui)
include_directories(${PROJECT_SOURCE_DIR})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(mmn17 main.cpp main.cpp dog.cpp dog.h items.cpp items.h room.cpp room.h lamp.cpp lamp.h menu.h
        menu.cpp window.h window.cpp floor.h floor.cpp blockedSquare.cpp blockedSquare.h)

add_executable(example example.c)

target_link_libraries(mmn17 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} imgui)
target_link_libraries(example ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})