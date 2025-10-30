#pragma once
#include "imgui.h"
#include "rlImGui.h"
#include "ContainerCurves.h"
#include "vector"
#include <iostream>




class UIimgui
{
public:
	UIimgui(containercurves::ContainerCurves* reg) : reg{ reg } {};

	void startUI();
	void endUI();
	
	
	
	void curveListBox();
	void navButtons();


	containercurves::ContainerCurves* reg;
private:
	static char elevenBytes[500];
	bool check = true;

	
};

