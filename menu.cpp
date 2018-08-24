//
// Created by Roman Smirnov on 22/08/2018.
//
#include <GL/glut.h>
#include "menu.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_freeglut.h"
#include "imgui/imgui_impl_opengl2.h"

static bool show_another_window = false;
static bool show_walk;
static bool show_turn_right;
static bool show_turn_left;

static bool show_move_back_left;
static bool show_move_back_right;
static bool show_move_top_left;
static bool show_move_top_right;

static bool show_head_up_and_down;
static bool show_head_right_and_left;

static bool show_tail_up_and_down;
static bool show_tail_right_and_left;


void Menu::setup(){
	// Setup ImGui binding
	ImGui::CreateContext();
	ImGui_ImplFreeGLUT_Init();
	ImGui_ImplFreeGLUT_InstallFuncs();
	ImGui_ImplOpenGL2_Init();
	ImGui::StyleColorsDark(); // Setup style
}

void Menu::reshape(int w, int h) {
	ImGui_ImplFreeGLUT_ReshapeFunc(w, h);
}

void Menu::keyboard(int key, int x, int y){
	ImGui_ImplFreeGLUT_KeyboardFunc(key, x, y);
}

void Menu::cleanup(){
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplFreeGLUT_Shutdown();
	ImGui::DestroyContext();
}

void Menu::draw(Dog* dog) {
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplFreeGLUT_NewFrame();

	static float f = 0.0f;
	ImGui::Begin("Scene Control Panel", &show_another_window);

	// Dog options

    ImGui::Spacing();
    ImGui::Text("Options");

	ImGui::Spacing();
	ImGui::Text("Dog Options");

	show_walk = dog->getWalk();
	ImGui::Checkbox("walk", &show_walk);
	dog->setWalk(show_walk);

	show_turn_right = dog->getTurnRight();
	ImGui::Checkbox("turn right", &show_turn_right);
	dog->setTurnRight(show_turn_right);

	show_turn_left = dog->getTurnLeft();
	ImGui::Checkbox("turn left", &show_turn_left);
	dog->setTurnLeft(show_turn_left);

	// Dog legs options
	ImGui::Spacing();
	ImGui::Text("Dog legs");

	ImGui::Checkbox("move back left leg", &show_move_back_left);
	dog->setMoveBackLeftLeg(show_move_back_left);

    ImGui::Checkbox("move front left leg", &show_move_top_left);
    dog->setMoveTopLeftLeg(show_move_top_left);

    ImGui::Checkbox("move back right leg", &show_move_back_right);
    dog->setMoveBackRightLeg(show_move_back_right);

    ImGui::Checkbox("move front right leg", &show_move_top_right);
    dog->setMoveTopRightLeg(show_move_top_right);

    // Dog head
    ImGui::Spacing();
    ImGui::Text("Dog head");
    ImGui::Checkbox("move head right&left", &show_head_right_and_left);
    dog->setHeadRightAndLeft(show_head_right_and_left);

    ImGui::Checkbox("move head up&down", &show_head_up_and_down);
    dog->setHeadUpAndDown(show_head_up_and_down);

    // Dog tail
    ImGui::Spacing();
    ImGui::Text("Dog tail");
    ImGui::Checkbox("move tail right&left", &show_tail_right_and_left);
    dog->setTailRightAndLeft(show_tail_right_and_left);

    ImGui::Checkbox("move tail up&down", &show_tail_up_and_down);
    dog->setTailUpAndDown(show_tail_up_and_down);


//    ‫‪adjust‬‬ ‫‪ambient‬‬ ‫‪light‬‬

//	ImGui::Spacing();
//	ImGui::Text("Camera Options");
//	ImGui::Checkbox("Keyboard Control Camera", &show_demo_window);
//
//	ImGui::Spacing();
//	ImGui::Text("Ambient Light Options");
//	ImGui::SliderFloat("Intensity", &f, 0.0f, 1.0f);
//
//	ImGui::Spacing();
//	ImGui::Text("Point Light Options");
//	ImGui::Checkbox("Keyboard Control Light", &show_demo_window);
//	ImGui::SliderFloat("Intensity", &f, 0.0f, 1.0f);
	ImGui::Spacing();
	ImGui::Button("Help");

	ImGui::Spacing();
	if (ImGui::Button("Quit")){
//        glutLeaveMainLoop();
        glutDestroyWindow(1);
	}

	ImGui::Spacing();
	ImGui::End();
	ImGui::Render();

	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}