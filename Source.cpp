#include<iostream>
#include"raylib.h"


#define RAYGUI_IMPLEMENTATION
#include"raygui.h"

#define MAX_INPUT_CHARS     9

int main()
{
	int width = 1020;
	int hidth = 620;

	bool showMessageBox = false;

	bool showMessageBox2 = false;

	const char te = '43';

	InitWindow(width, hidth, "MathInRaylib");

	Camera3D cam = { 0 };

	cam.position = Vector3{ 40.0f, 60.0f, 40.0f, };
	cam.target = Vector3{ 0.0f, 0.0f, 0.0f };
	cam.up = Vector3{ 0.0f, 2.0f, 0.0f };
	cam.fovy = 45.0f;
	cam.projection = CAMERA_PERSPECTIVE;

	//----------------------------
	char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
	int letterCount = 0;

	Rectangle textBox = { width / 2.0f - 470, 50, 250, 50 };
	bool mouseOnText = false;

	int framesCounter = 0;
	//----------------------------


	Vector3 cubePosition = { 0.0f, 2.0f, 0.0f };

	Vector2 cubeScreenPosition = { 0.0f, 10.0f };
	Vector2 cubeScreenPosition0 = { 0.0f, 10.0f };
	Vector2 cubeScreenPositionX = { 0.0f, 10.0f };
	Vector2 cubeScreenPositionY = { 0.0f, 10.0f };
	Vector2 cubeScreenPositionZ = { 0.0f, 10.0f };

	Ray ray = { 0 };                    
	RayCollision collision = { 0 };

	bool exit = false;

	DisableCursor();    
	SetTargetFPS(60);

	while (WindowShouldClose() == false && exit == false)
	{
		if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
		else mouseOnText = false;

		if (mouseOnText)
		{
			// Set the window's cursor to the I-Beam
			SetMouseCursor(MOUSE_CURSOR_IBEAM);

			// Get char pressed (unicode character) on the queue
			int key = GetCharPressed();

			// Check if more characters have been pressed on the same frame
			while (key > 0)
			{
				// NOTE: Only allow keys in range [32..125]
				if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS))
				{
					name[letterCount] = (char)key;
					name[letterCount + 1] = '\0'; // Add null terminator at the end of the string
					letterCount++;
				}

				key = GetCharPressed();  // Check next character in the queue
			}

			if (IsKeyPressed(KEY_BACKSPACE))
			{
				letterCount--;
				if (letterCount < 0) letterCount = 0;
				name[letterCount] = '\0';
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

		if (mouseOnText) framesCounter++;
		else framesCounter = 0;



		//---------------Выход\Вход_в_режим_камеры--------------//
		if (IsCursorHidden()) UpdateCamera(&cam, CAMERA_FIRST_PERSON);

		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{
			if (IsCursorHidden()) EnableCursor();
			else DisableCursor();
		}

		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (!collision.hit)
			{
				ray = GetScreenToWorldRay(GetMousePosition(), cam);
			}
			else collision.hit = false;
		}
		//-------------------------------------------------------//


		cubeScreenPosition0 = GetWorldToScreen(Vector3{ 0.0f, 0.0f, cubePosition.z }, cam);
		cubeScreenPositionX = GetWorldToScreen(Vector3{ 0.5f, 30.0f, cubePosition.z }, cam);
		cubeScreenPositionZ = GetWorldToScreen(Vector3{ 30.0f,0.5f, cubePosition.z }, cam);
		cubeScreenPositionY = GetWorldToScreen(Vector3{ 0.5f, 0.5f, 30.0f}, cam);

		Vector2 mousePosition = GetMousePosition();
		bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

		BeginDrawing();
			ClearBackground(WHITE);

			



			//-----MENU-------------
			//DrawRectangle(10, 10, 240, 523, SKYBLUE);
			//DrawRectangleLines(10, 10, 240, 523, BLUE);
	

		DrawRectangle(10, 10, 325, 520, SKYBLUE);
		DrawRectangleLines(10, 10, 325, 520, BLUE);

		//----------------------Текст_в_Рамках-----------------------------//
		DrawText("Zdes vvod", 20, 20, 20, BLACK);

		DrawText("Coordinates of Derivatives", 20, 320, 20, BLACK);

		DrawText("Point Coordinates", 20, 410, 20, BLACK);
		//------------------------------------------------------------//
		
		//------------------------------//
		DrawRectangleRec(textBox, LIGHTGRAY);
		if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
		else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

		DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

		DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, DARKGRAY);

		if (mouseOnText)
		{
			if (letterCount < MAX_INPUT_CHARS)
			{
					// Draw blinking underscore char
				if (((framesCounter / 20) % 2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
			}
			else DrawText("Press BACKSPACE to delete chars...", 430, 100, 20, GRAY);
		}
		//-----------------------------------//

		
		//-------------Кнопки_Raygui----------------------//
		if (GuiButton(Rectangle{ 24, 350, 130, 40 }, GuiIconText(ICON_FILE_PEER, "Show Message"))) showMessageBox = true;

		if (showMessageBox)
		{
			int result = GuiMessageBox(Rectangle{ 310, 110, 250, 100 },
				"Message Box", "Hi! This is a message!", "Nice;Cool");
			if (result >= 0) showMessageBox = false;
		}
		//--------------------

		if (GuiButton(Rectangle{ 24, 450, 130, 40 }, GuiIconText(ICON_FILE_PEER, "Show Message"))) showMessageBox2 = true;

		if (showMessageBox2)
		{
			int result = GuiMessageBox(Rectangle{ 410, 210, 250, 100 },
				"Message Box", "Hi! This is a message!", "Nice;Cool");

			if (result >= 0) showMessageBox2 = false;
		}
		//-----------------------------------//


		BeginMode3D(cam);
	
		DrawLine3D({ 0.0f, 0.0f, 0.0f }, { 0.0f, 30.0f, 0.0f }, DARKGRAY);

		DrawGrid(30, 2);

			EndMode3D();

			//-------------------Текст_в_3D--------------------------//
			DrawText("0", (int)cubeScreenPosition0.x, (int)cubeScreenPosition0.y, 15, BLACK);
			DrawText("X", (int)cubeScreenPositionX.x, (int)cubeScreenPositionX.y, 25, BLACK);
			DrawText("Y", (int)cubeScreenPositionY.x, (int)cubeScreenPositionY.y, 25, BLACK);
			DrawText("Z", (int)cubeScreenPositionZ.x, (int)cubeScreenPositionZ.y, 25, BLACK);
			//--------------------------------------------------//

		EndDrawing();
	}
	CloseWindow();
	
	
	return 0;

}

bool IsAnyKeyPressed()
{
	bool keyPressed = false;
	int key = GetKeyPressed();

	if ((key >= 32) && (key <= 126)) keyPressed = true;

	return keyPressed;
}