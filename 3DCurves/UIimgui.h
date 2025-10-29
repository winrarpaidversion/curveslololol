#pragma once
#include "imgui.h"
#include "rlImGui.h"
#include "ContainerCurves.h"
#include "vector"
class UIimgui
{
public:
	
	void startUI();
	void endUI();
	void ContainerRender(containercurves::ContainerCurves& reg);
private:
	static char elevenBytes[500];
	bool check = true;

	
};

