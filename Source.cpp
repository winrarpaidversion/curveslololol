#include<iostream>
#include"raylib.h"
#include <array>
#include "ContainerFigure.h"
#include "SearchCoordinat.h"
int main()
{
	Camera3D cam = { 0 };
	cam.position = Vector3{ 10.0f, 10.0f, 10.0f, };
	cam.target = Vector3{ 0.0f, 0.0f, 0.0f };
	cam.up = Vector3{ 0.0f, 1.0f, 0.0f };
	cam.fovy = 45.0f;
	cam.projection = CAMERA_PERSPECTIVE;
	Vector2 isMouse = GetMousePosition();
	Rectangle recNext = { 500, 600, 100, 100, };
	Rectangle recPrev = { 20,30, 30,40, };
	bool isNext = false;
	bool isPrev = false;
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	Vector3 cubePosition = { x, y, z };
	Vector3 Elipse = { x, y, z };

	int width = 1000;
	int hidth = 800;
	bool checkMouseNext = CheckCollisionPointRec(isMouse, recNext);
	bool checkMousePrev = CheckCollisionPointRec(isMouse, recPrev);
	bool PressButton = IsMouseButtonPressed(MOUSE_BUTTON_LEFT && checkMouseNext);

	InitWindow(width, hidth, "MathInRaylib");




	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		UpdateCamera(&cam, CAMERA_FREE);
		if (PressButton)
		{
			isNext = true;
			TraceLog(1, "click");
			DrawText("click!", 400, 600, 10, BLACK);

		}
		else if (checkMouseNext)
		{

			DrawText("holdButton", 500, 600, 10, BLACK);
		}
	
		BeginDrawing();
		ClearBackground(WHITE);
		BeginMode3D(cam);
		DrawGrid(100, 1.0f);
		DrawCube(cubePosition, 10.0f, 10.0f, 10.0f, BLUE);


		EndMode3D();
		DrawRectangle(500, 600, 100, 100, RED);


		EndDrawing();

	}
	CloseWindow();


	return 0;

};