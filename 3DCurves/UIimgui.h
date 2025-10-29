#pragma once
#include "imgui.h"
#include "rlImGui.h"
#include "ContainerCurves.h"
#include "vector"
#include <iostream>

class UIimgui
{
public:

	void startUI();
	void endUI();
	void ContainerRender(containercurves::ContainerCurves* reg);
private:
	
	bool check = true;
	
};

