cmake_minimum_required(VERSION 3.6)

#find_package(OpenGL REQUIRED)
#find_package(GLut REQUIRED)

add_library(
        imgui STATIC
        imconfig.h
        imgui.cpp
        imgui.h
        imgui_impl_opengl2.cpp
        imgui_impl_opengl2.h
        imgui_impl_freeglut.cpp
        imgui_impl_freeglut.h
        imgui_demo.cpp
        imgui_draw.cpp
        imgui_internal.h
        stb_rect_pack.h
        stb_textedit.h
        stb_truetype.h
)