cmake_minimum_required(VERSION 3.10)
project(mmn-17-computer-graphics)

set(CMAKE_CXX_STANDARD 17)

include_directories(imgui/include)
include_directories(glew/include)
include_directories(freeglut/include)

find_package (OpenGL REQUIRED)
set(IMGUI_LIBRARY ${PROJECT_SOURCE_DIR}/imgui/lib/imgui.lib)
set(GLEW_LIBRARY ${PROJECT_SOURCE_DIR}/glew/lib/glew32.lib)
set(GLUT_LIBRARY ${PROJECT_SOURCE_DIR}/freeglut/lib/freeglut.lib)

add_executable(mmn17 src/main.cpp src/main.cpp src/dog.cpp src/dog.h src/items.cpp src/items.h src/room.cpp src/room.h src/lamp.cpp src/lamp.h src/menu.h
        src/menu.cpp src/window.h src/window.cpp src/floor.h src/floor.cpp src/blockedSquare.cpp src/blockedSquare.h src/stb_image.cpp src/stb_image.h src/pch.cpp src/pch.h)


target_link_libraries(mmn17 ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} ${GLUT_LIBRARY} ${IMGUI_LIBRARY})