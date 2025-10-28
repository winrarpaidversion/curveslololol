#include "UIimgui.h"
void UIimgui::startUI()
{
	
	rlImGuiBegin();

	static char elevenBytes[500] = {};


	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar;
	static bool no_menu = true;
	if (!no_menu)           window_flags |= ImGuiWindowFlags_MenuBar;
	//	ImGui::ShowDemoWindow(&open);


	ImGui::SetNextWindowSize(ImVec2{ 400,300 });
	if (ImGui::Begin("Hello", nullptr, window_flags | no_menu))
	{

		ImGui::InputText("Input", elevenBytes, sizeof(elevenBytes));
		/*ImGui::InputText();*/
		if (ImGui::Button("Chek", ImVec2{ 100,30 }))
		{

		}

	}
	ImGui::End();

}

void UIimgui::endUI()
{
	rlImGuiEnd();
}
void UIimgui::ContainerRender(containercurves::ContainerCurves* reg)
{

	if (ImGui::Button("Prev container"))
	{
		check = true;
		reg->PrevCurve();
	}
	if (ImGui::Button("Next container"))
	{
		check = true;
		reg->NextCurve();
	}
	//ImGui::ListBox("ContainerView", &currentIndex, (reg->container, IM_ARRAYSIZE(reg->container), 4);
	ImGui::End();
}