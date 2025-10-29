#include "RenderInterface.h"
#include <iostream>
#include "UIimgui.h"

int main()
{
	
	int width = 1720;
	int height = 880;

	InitWindow(width, height, "MathInRaylib");
	RayCollision collision = { 0 };
	Camera3D cam = { 0 };
	Vector3 cubePosition = { 0.0f, 2.0f, 0.0f };
	cam.position = Vector3{ 60.0f, 80.0f, 60.0f, };
	cam.target = Vector3{ 0.0f, 0.0f, 0.0f };
	cam.up = Vector3{ 0.0f, 2.0f, 0.0f };
	cam.fovy = 45.0f;
	cam.projection = CAMERA_PERSPECTIVE;
	Ray ray = { 0 };

	containercurves::ContainerCurves containercurves;
	RenderGui::RenderInterface renderinterface;
	UIimgui ui;

	bool exit = false;
	bool secret = true;

	Vector2 mousePosition = GetMousePosition();
	bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	rlImGuiSetup(true);

	DisableCursor();
	SetTargetFPS(60);

	while (WindowShouldClose() == false && exit == false)
	{

		containercurves.initializeContainers();
		renderinterface.calculatePosition(cam, cubePosition);

		//---------------Выход\Вход_в_режим_камеры--------------//
		renderinterface.DrawExitMouse(cam, collision, ray);
		//-------------------------------------------------------//

		BeginDrawing();
		
		
		ClearBackground(WHITE);


		ui.startUI();

		//-----------------Рамка_Меню--------------------//


		BeginMode3D(cam);
		containercurves.DrawCurrentContainer();
		renderinterface.Draw3DLine();

		EndMode3D();
		renderinterface.Draws3DText();

		
		ui.endUI();
		EndDrawing();
		
	}
	
	CloseWindow();

	return 0;

}