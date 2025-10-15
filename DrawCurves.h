#pragma once
#include "Curve.h"
class DrawCurves
{
	
public:
	//Сделать класс -найс
	//Сделать в нём обычные функции вызова draw-ов? Может лучше по параметрам сделать или же просто вызывать их?
	void DrawElipse()
	{
		DrawEllipse(1, 2, 3.14f, 3.14f, BLACK);
	};
	void DrawCubes()
	{
		DrawCube(Vector3{ 0,0,0 }, 10.0f, 10.0f, 10.0f, BLANK);
	};
	void DrawHelix()
	{
	/*	DrawCylinder(Vector3{ 0,0,0 }, 3.0f, 3.0f, 3.0f, 3, BLANK);*/
	};

};

