#pragma once
#include <cstdlib> 
#include <ctime>   
#include<iostream>
#include "Cube.h"
#include "Elipse.h"
#include "raymath.h"
#include "raylib.h"


class SearchCoordinat : Curve
{

private: 
	Vector3 FigurePosition = { 0.0f,0.0f,0.0f };
	int randomNum = rand() % 100;
public:
	
	
	void searchCoordinatCube()
	{
		
		srand(time(0));
		Cube cube = { randomNum,randomNum,randomNum };
		
		float result = Lerp(cube.x, cube.y, cube.z);
		
		DrawCube(FigurePosition, cube.x, cube.y, cube.z, BLUE);
		DrawText(TextFormat("result",result), 10, 20,10, BLACK);



	};
	void searchCoordinatElipse()
	{
		srand(time(0));
		Elipse elipse = { randomNum,randomNum,randomNum,randomNum,randomNum };
		

	}

};

