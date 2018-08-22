cmake_minimum_required(VERSION 3.10)
project(mmn-17-computer-graphics)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(./imgui)
set(SOURCE_FILES main.cpp dog.cpp dog.h items.cpp items.h)
set(EXECUTABLE_NAME mmn17
        )
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

target_link_libraries(${EXECUTABLE_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} imgui)
