#include<iostream>
#include"raylib.h"
#include "ContainerFigure.h"

int main()
{
	Camera3D cam = { 0 };
	cam.position = Vector3{ 10.0f, 10.0f, 10.0f, };
	cam.target = Vector3{ 0.0f, 0.0f, 0.0f };
	cam.up = Vector3{ 0.0f, 1.0f, 0.0f };
	cam.fovy = 45.0f;
	cam.projection = CAMERA_PERSPECTIVE;

	Rectangle recNext = { 500, 600, 100, 100};
	Rectangle recPrev = { 300,600, 100,100};

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	ContainerFigure containerFigure;
	containerFigure.initializeContainers();
	int width = 1000;
	int hidth = 800;
	
	InitWindow(width, hidth, "MathInRaylib");




	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
	
		bool isNext = false;
		bool isPrev = false;
		Vector2 isMouse = GetMousePosition();
		bool checkMouseNext = CheckCollisionPointRec(isMouse, recNext);
		bool checkMousePrev = CheckCollisionPointRec(isMouse, recPrev);
		bool PressButtonNext = IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && checkMouseNext;
		bool PressButtonPrev = IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && checkMousePrev;
		UpdateCamera(&cam, CAMERA_FREE);
		if (PressButtonNext)
		{
			containerFigure.NextCurve();

		}
		if (PressButtonPrev)
		{
			containerFigure.PrevCurve();

		}

		BeginDrawing();
		ClearBackground(WHITE);

		BeginMode3D(cam);
		DrawGrid(100, 1.0f);

		containerFigure.DrawCurrentContainer();
		EndMode3D();

		DrawRectangleRec(recNext, BLUE);
		DrawRectangleRec(recPrev, BLACK);
		if (checkMouseNext)
		{
			DrawText("Next Curve", 500, 580, 15, GRAY);
		}
		if (checkMousePrev)
		{
			DrawText("Prev Curve", 300, 580, 15, GRAY);
		}
		EndDrawing();
		DrawText(TextFormat("Current total: %d", containerFigure.GetTotalContainer()), 20, 20, 20, BLACK);
	}
	CloseWindow();


	return 0;

};