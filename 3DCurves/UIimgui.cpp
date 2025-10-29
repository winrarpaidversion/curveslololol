#include "UIimgui.h"
void UIimgui::startUI()
{

	rlImGuiBegin();




	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar;
	static bool no_menu = true;
	if (!no_menu) window_flags |= ImGuiWindowFlags_MenuBar;
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
void UIimgui::ContainerRender(containercurves::ContainerCurves& reg)
{

	const char* NameItem[10];
	if (ImGui::Button("Prev container"))
	{
		check = true;
		reg.PrevCurve();
	}
	if (ImGui::Button("Next container"))
	{
		check = true;
		reg.NextCurve();
	}


	/*if (ImGui::BeginListBox("ContainerView"))
	{
		for (int i = 0; i < reg.container.size(); i++)
		{
			
			NameItem[i] = reg.container[i]->getName();
			const bool InSelect = (reg.CurrentLevel == i);
			if(ImGui::Selectable(NameItem, &InSelect))
			{
				reg.CurrentLevel = i;

			}
		}
	
	}
	ImGui::EndListBox();*/
	//ImGui::BeginListBox("ContainerView", ImVec2{300,300});
	//for (int i = 0; i < reg->container.size(); i++)
	//{
	//	const bool inSelect = (reg->CurrentLevel == i);
	//	if(ImGui::Selectable("label",reg->container[i], inSelect))
	//	{
	//		reg->CurrentLevel = i;
	//	}
	//}
	ImGui::End();
}