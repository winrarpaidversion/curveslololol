#pragma once
#include "imgui.h"
#include "rlImGui.h"
#include "ContainerCurves.h"
#include "vector"
#include <iostream>


//static char Xelement[500] = {};
//static char Yelement[500] = {};
//static char Zelement[500] = {};
//static char Aelement[500] = {};
//static char Belement[500] = {};
//static char Stepelement[500] = {};
//static char Radiuselement[500] = {};
static char Nameelement[500] = {};
static float col1[3] = { 1,1,1 };
class UIimgui
{
public:
	UIimgui(containercurves::ContainerCurves* reg) : reg{ reg } {};
	void startUI();
	void endUI();
	void curveListBox();
	void navButtons();
	void generateRandomCurve();
	void inputBoxes();
	void showInfo();
	void showInfoCircles();
	char randomChar();

	containercurves::ContainerCurves* reg;
	float InputX;
	float InputY;
	float InputZ;
	float InputA;
	float InputB;
	float InputStep;
	float InputRadius;
	float angleX;
	float angleY;
	float angleZ;
	float customT;
	float t = PI / 4;
	std::string name;
	static inline const char* items[] = { "Circle", "Ellipse", "Helix" };
private:
	static char elevenBytes[500];
	bool check = true;
	static int item_selected_idx;
	int item_highlighted_idx;
};

