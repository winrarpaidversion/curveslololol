#define RAYGUI_CPP_TEXT_INPUT_BOX_H
#include <raylib.h>
#include "RenderInterface.h"
#include <iostream>
#include "ContainerCurves.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION

#define MAX_INPUT_CHARS     20

int main()
{
	GuiEnable();
	GuiUnlock();
	int width = 1720;
	int height = 880;
	bool showMessageBox = false;
	bool showMessageBox2 = false;
	bool showMessageBox3 = false;
	char* buffer;
	buffer = (char*)calloc(1024, sizeof(char));

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

	bool exit = false;
	bool secret = true;

	Vector2 mousePosition = GetMousePosition();
	bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

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

		//-----------------Рамка_Меню--------------------//
		renderinterface.DrawFrame();

		if (GuiButton(Rectangle{ 24, 350, 140, 40 }, GuiIconText(ICON_FILE_PEER, "Next Curve"))) showMessageBox = true;
		if (showMessageBox)
		{
			/*int result = GuiMessageBox(Rectangle{ 310, 110, 275, 125 },
				"Message Box", "Hi! This is a message!", "Ok;Censel");
			if (result >= 0) showMessageBox = false;*/
			containercurves.NextCurve();
			std::cout << "NextCurve" << std::endl;
			showMessageBox = false;

		}


		if (GuiButton(Rectangle{ 24, 450, 140, 40 }, GuiIconText(ICON_FILE_PEER, "Prev Curve"))) showMessageBox2 = true;

		if (showMessageBox2)
		{
			/*	int result = GuiMessageBox(Rectangle{ 410, 210, 275, 125 },
					"Message Box", "Hi! This is a message111!", "Ok;Censel");

				if (result >= 0) showMessageBox2 = false;*/
			containercurves.PrevCurve();
			std::cout << "PrevCurve" << std::endl;
			showMessageBox2 = false;

		}
		if (GuiButton(Rectangle{ 24, 50, 140, 40 }, GuiIconText(ICON_PENCIL_BIG, "Input Box"))) showMessageBox3 = true;

		if (showMessageBox3)
		{
			int result = GuiTextInputBox(Rectangle{ 350, 9, 400, 110 },
				"Imput Box", 0, "Ok;Censel", buffer, 1024, 0);
			if (result >= 0) showMessageBox3 = false;

		}
		BeginMode3D(cam);
		containercurves.DrawCurrentContainer();
		renderinterface.Draw3DLine();

		EndMode3D();
		renderinterface.Draws3DText();

		EndDrawing();

	}

	CloseWindow();

	return 0;

}