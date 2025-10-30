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
	containercurves.initializeContainers();
	RenderGui::RenderInterface renderinterface;
	UIimgui ui{&containercurves};

	bool exit = false;
	bool secret = true;

	Circle circle{ Vector3{10,20, 0}, 50, "My Circle" ,BLACK, 45};
	std::vector<Vector3> points;
	int segments = 100;
	for (int i = 0; i <= segments; i++)
	{
		float t = 2 * PI * i / segments;
		auto p = circle.getPoint(t);
		points.push_back(Vector3{ p.x, p.y, p.z });
	}

	Vector2 mousePosition = GetMousePosition();
	bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

	rlImGuiSetup(true);

	DisableCursor();
	SetTargetFPS(60);

	while (WindowShouldClose() == false && exit == false)
	{

		
		renderinterface.calculatePosition(cam, cubePosition);

		//---------------Выход\Вход_в_режим_камеры--------------//
		renderinterface.DrawExitMouse(cam, collision, ray);
		//-------------------------------------------------------//

		BeginDrawing();
		
		
		ClearBackground(WHITE);
		

		ui.startUI();
		
		//-----------------Рамка_Меню--------------------//


		BeginMode3D(cam);
		//containercurves.DrawCurrentContainer();
		renderinterface.Draw3DLine();

		for (int i = 0; i < points.size() - 1; i++)
		{
			DrawLine3D(points[i], points[i + 1], circle.getColor());
		}

		EndMode3D();
		renderinterface.Draws3DText();

		
		ui.endUI();
		EndDrawing();
		
	}
	
	CloseWindow();

	return 0;

}