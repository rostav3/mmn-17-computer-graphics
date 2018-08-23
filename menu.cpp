//
// Created by Roman Smirnov on 22/08/2018.
//

#include "menu.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_freeglut.h"
#include "imgui/imgui_impl_opengl2.h"

static bool show_demo_window = true;
static bool show_another_window = false;

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

void Menu::draw() {
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplFreeGLUT_NewFrame();

	static float f = 0.0f;
	ImGui::Begin("Scene Control Panel", &show_another_window);

	ImGui::Spacing();
	ImGui::Text("Camera Options");
	ImGui::Checkbox("Keyboard Control Camera", &show_demo_window);

	ImGui::Spacing();
	ImGui::Text("Ambient Light Options");
	ImGui::SliderFloat("Intensity", &f, 0.0f, 1.0f);

	ImGui::Spacing();
	ImGui::Text("Point Light Options");
	ImGui::Checkbox("Keyboard Control Light", &show_demo_window);
	ImGui::SliderFloat("Intensity", &f, 0.0f, 1.0f);

	ImGui::Spacing();
	ImGui::Text("Dog Options");
	ImGui::Checkbox("Dog View Point", &show_demo_window);
	ImGui::Checkbox("Keyboard Control Dog", &show_demo_window);
	ImGui::Checkbox("Tail Animation", &show_demo_window);      // Edit bools storing our windows open/close state
	ImGui::Checkbox("Head Animation", &show_another_window);
	ImGui::Checkbox("Legs Animation", &show_another_window);

	ImGui::Spacing();
	ImGui::Button("Help");

	ImGui::Spacing();
	ImGui::Button("Quit");

	ImGui::Spacing();
	ImGui::End();
	ImGui::Render();

	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}