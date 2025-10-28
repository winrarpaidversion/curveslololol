#include "UIimgui.h"
void UIimgui::startUI()
{
	containercurves::ContainerCurves container;
	rlImGuiBegin();

	bool open = true;
	ImGui::ShowDemoWindow(&open);

	ImGui::SetNextWindowSize(ImVec2{ 500,500 });
	if (ImGui::Begin("Hello"), &open)
	{
		ContainerRender(&container);
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