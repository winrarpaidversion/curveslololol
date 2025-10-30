#include "UIimgui.h"
void StyleColorsSpectrum() {
	ImGuiStyle& style = ImGui::GetStyle();
	style.Alpha = 1.0;
	style.WindowRounding = 3;
	style.GrabRounding = 1;
	style.GrabMinSize = 20;
	style.FrameRounding = 3;

	style.Colors[ImGuiCol_Text] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.00f, 0.40f, 0.41f, 1.00f);
	style.Colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
	style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style.Colors[ImGuiCol_FrameBg] = ImVec4(0.44f, 0.80f, 0.80f, 0.18f);
	style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.44f, 0.80f, 0.80f, 0.27f);
	style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.44f, 0.81f, 0.86f, 0.66f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(0.14f, 0.18f, 0.21f, 0.73f);
	style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.27f);
	style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
	style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.22f, 0.29f, 0.30f, 0.71f);
	style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.44f);
	style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
	style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 1.00f, 1.00f, 0.68f);
	style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.36f);
	style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.76f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.65f, 0.65f, 0.46f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.01f, 1.00f, 1.00f, 0.43f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.62f);
	style.Colors[ImGuiCol_Header] = ImVec4(0.00f, 1.00f, 1.00f, 0.33f);
	style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.42f);
	style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
	style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
	style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
	style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotLines] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
	style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 1.00f, 1.00f, 0.22f);

}
void UIimgui::startUI()
{
	StyleColorsSpectrum();
	const char* items[] = { "Circle", "Ellipse", "Helix" };
	static bool item_highlight = false;
	int item_highlighted_idx = -1;
	static int item_selected_idx = 0;

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	rlImGuiBegin();

	static char elevenBytes1[500] = {};
	static char elevenBytes2[500] = {};
	static char elevenBytes3[500] = {};

	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar;
	static bool no_menu = true;
	if (!no_menu)
		window_flags |= ImGuiWindowFlags_MenuBar;
	//	ImGui::ShowDemoWindow(&open);

	ImGui::SetNextWindowSize(ImVec2{ 425,880 });
	ImGui::SetNextWindowPos(ImVec2{ 0,0 });
	static float col1[3] = { 1,1,1 };


	if (ImGui::Begin("Hello", nullptr, window_flags | no_menu))
	{

		ImGui::InputTextMultiline(":X", elevenBytes1, sizeof(elevenBytes1), ImVec2{ 100,18 }); 
		ImGui::SameLine();
		ImGui::InputTextMultiline(":Y", elevenBytes2, sizeof(elevenBytes2), ImVec2{ 100,18 }); 
		ImGui::SameLine();
		ImGui::InputTextMultiline(":Z", elevenBytes3, sizeof(elevenBytes3), ImVec2{ 100,18 });

		ImGui::ColorEdit3("Color", col1);
		/*ImGui::InputText();*/
		
		if (ImGui::BeginListBox("List Boxes"))
		{
			for (int n = 0; n < IM_ARRAYSIZE(items); n++)
			{
				const bool is_selected = (item_selected_idx == n);
				if (ImGui::Selectable(items[n], is_selected))
					item_selected_idx = n;

				if (item_highlight && ImGui::IsItemHovered())
					item_highlighted_idx = n;

				// Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndListBox();
		}
		if (ImGui::Button("Add", ImVec2{ 100,30 }))
		{
			
		}
		ImGui::SameLine();
		if (ImGui::Button("Random", ImVec2{ 100,30 }))
		{
			// TODO!!!!
		}
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
		navButtons();
		curveListBox();
	}
	


}

void UIimgui::endUI()
{
	ImGui::End();
	rlImGuiEnd();
	
}
void UIimgui::curveListBox()
{
	if (ImGui::BeginListBox("All curves"))
	{
		if (!reg->container.empty())
		{
			for (int i = 0; i < reg->container.size(); i++)
			{
				const bool InSelect = (reg->CurrentLevel == i);
				if (ImGui::Selectable(reg->container[i]->getName().c_str(), &InSelect))
				{
					reg->CurrentLevel = i;
				}
			}
		}
		else {
			ImGui::Text("NO CURVES");
		}
	}
	ImGui::EndListBox();
}

void UIimgui::navButtons()
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
}
