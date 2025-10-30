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
int UIimgui::item_selected_idx = 0;

void UIimgui::startUI()
{
	StyleColorsSpectrum();
	
	static bool item_highlight = false;
	item_highlighted_idx = -1;
	
	ImGuiIO& io = ImGui::GetIO();
	io.Fonts->AddFontFromFileTTF("Font/arialmt.ttf", 14.0f);

	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	
	rlImGuiBegin();


	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoTitleBar;

	//	ImGui::ShowDemoWindow(&open);

	ImGui::SetNextWindowSize(ImVec2{ 425,880 });
	ImGui::SetNextWindowPos(ImVec2{ 0,0 });


	ImGui::PushFont(io.Fonts->Fonts[1]);
	
	

	if (ImGui::Begin("Hello", nullptr, window_flags ))
	{
		inputBoxes();
		if (ImGui::ColorEdit3("Color", col1, ImGuiColorEditFlags_Uint8))
		{
			
		}
		
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
	
		if (ImGui::Button("Add", ImVec2{ 90,25 }))
		{
			name = Nameelement;
			Color color{ col1[0] * 255 + 0.5, col1[1] * 255 + 0.5, col1[2] * 255 + 0.5, 255 };
			
			switch (item_selected_idx)
			{
			case 0:
				reg->AddCurve(std::make_shared<Circle>(Vector3{ InputX, InputY, InputZ }, InputRadius, name, color, angleX, angleY, angleZ));

				break;
			case 1:
				reg->AddCurve(std::make_shared<Ellipse>(Vector3{ InputX, InputY, InputZ }, InputRadius, InputA, InputB, name, color, angleX, angleY, angleZ));
				break;
			case 2:
				reg->AddCurve(std::make_shared<Helix>(Vector3{ InputX, InputY, InputZ }, InputRadius, InputStep, name, color, angleX, angleY, angleZ));
				break;
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Delete", ImVec2{ 90,25 }))
		{
			reg->container.erase(reg->container.begin() + reg->CurrentLevel);

			if (reg->CurrentLevel >= reg->container.size())
			{
				if (!reg->container.empty())
					reg->CurrentLevel = reg->container.size() - 1;
				else
					reg->CurrentLevel = 0;
			}
		}
		ImGui::SameLine();
		if (ImGui::Button("Random", ImVec2{ 90,25 }))
		{	
			generateRandomCurve();
		}

		navButtons();

		curveListBox();
		
		showInfo();

		showInfoCircles();
	}
	ImGui::PopFont();
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
				if (ImGui::Selectable(reg->container[i]->getName().c_str(), InSelect))
				{
					reg->CurrentLevel = i;
				}
				if (InSelect)
				{
					ImGui::SetItemDefaultFocus();
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

	ImGui::SameLine();
	if (ImGui::Button("Next container"))
	{
		check = true;
		reg->NextCurve();
	}
	ImGui::Text("");
}

void UIimgui::generateRandomCurve()
{
	int coords[3];
	float angles[3];
	unsigned int r, g, b;

	for (int i = 0; i < 3; i++)
	{
		coords[i] = GetRandomValue(0, 100);
	}
	for (int i = 0; i < 3; i++)
	{
		angles[i] = GetRandomValue(0, 100);
	}
	r = GetRandomValue(0, 256);
	g = GetRandomValue(0, 256);
	b = GetRandomValue(0, 256);
	for (int num : coords)
	{
		std::cout << num << std::endl;
	}
	std::cout << std::endl;
	for (int num : angles)
	{
		std::cout << num << std::endl;
	}
	Color color = { r,g,b,255 };
	int curveType = GetRandomValue(0,2);

}

void UIimgui::inputBoxes()
{
	ImGui::SetNextItemWidth(50);
	ImGui::InputFloat(":X", &InputX);
	ImGui::SetNextItemWidth(50);
	ImGui::InputFloat(":Y", &InputY);
	ImGui::SetNextItemWidth(50);
	ImGui::InputFloat(":Z", &InputZ);
	ImGui::SetNextItemWidth(50);
	ImGui::InputFloat(":Radius", &InputRadius);
	ImGui::SetNextItemWidth(50);
	ImGui::InputFloat(":angle-X", &angleX);
	ImGui::SetNextItemWidth(50);
	ImGui::InputFloat(":angle-Y", &angleY);
	ImGui::SetNextItemWidth(50);
	ImGui::InputFloat(":angle-Z", &angleZ);

	if (item_selected_idx == 1)
	{
		ImGui::SetNextItemWidth(50);
		ImGui::InputFloat(":A", &InputA);
		ImGui::SetNextItemWidth(50);
		ImGui::InputFloat(":B", &InputB);
		ImGui::SetNextItemWidth(50);
	}
	else if (item_selected_idx == 2)
	{
		ImGui::SetNextItemWidth(50);
		ImGui::InputFloat(":Step", &InputStep);

	}
	ImGui::InputTextMultiline(":Name", Nameelement, sizeof(Nameelement), ImVec2{ 200,20 });
}

void UIimgui::showInfo()
{
	if (!reg->container.empty())
	{
		auto& currentCurve = reg->container[reg->CurrentLevel];

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		ImGui::Text("Curve information:");

		ImGui::Text("Name: %s", currentCurve->getName().c_str());
		ImGui::Text("Type: %s", currentCurve->getClass().c_str());

		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		ImGui::Text("Parameter input:");
		ImGui::SetNextItemWidth(200);
		if (ImGui::InputFloat("t parameter", &customT, 0.1, 1.0))
		{

		}
		float radT = customT * DEG2RAD;
		Vector3 p = currentCurve->getPoint(radT);
		Vector3 d = currentCurve->getDerivative(radT);

		ImGui::Text("Results for t = %.3f", radT);
		ImGui::Text("Point: (%.5f, %.5f, %.5f)", p.x, p.y, p.z);
		ImGui::Text("Derivative: (%.5f, %.5f, %.5f)", d.x, d.y, d.z);
	}
}

void UIimgui::showInfoCircles()
{
	float t = PI/4;

	if (reg->circleContainer.empty())
	{
		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();
		ImGui::Text("No Circle objects found in the array.");
		return;
	}

	ImGui::Spacing();
	ImGui::Separator();
	ImGui::Spacing();
	ImGui::Text("ALL CIRCLES (t = PI/4)");
	ImGui::Spacing();
	ImGui::Text("Total Circle objects: %zu", reg->circleContainer.size());
	ImGui::Spacing();

	for (const auto& curve : reg->circleContainer)
	{
		ImGui::Spacing();
		ImGui::Separator();
		ImGui::Spacing();

		ImGui::Text("Name: %s", curve->getName().c_str());
		
		Vector3 p = curve->getPoint(t);
		Vector3 d = curve->getDerivative(t);

		ImGui::Text("Point at PI/4: (%.5f, %.5f, %.5f)", p.x, p.y, p.z);
		ImGui::Text("Derivative at PI/4: (%.5f, %.5f, %.5f)", d.x, d.y, d.z);
	}
}

char UIimgui::randomChar()
{
	int random = GetRandomValue(0, 26);

	return 'A' + random;
}

