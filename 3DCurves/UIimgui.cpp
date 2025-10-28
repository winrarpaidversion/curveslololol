#include "UIimgui.h"

void UIimgui::startUI()
{
	rlImGuiBegin();

	bool open = true;
	ImGui::ShowDemoWindow(&open);

	ImGui::SetNextWindowSize(ImVec2{ 500,500 });
	if (ImGui::Begin("Hello"), &open)
	{

	}

}

void UIimgui::endUI()
{
	rlImGuiEnd();
}
