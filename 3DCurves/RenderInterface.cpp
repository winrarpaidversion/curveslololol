#include "RenderInterface.h"

namespace RenderGui
{

	void RenderInterface::DrawExitMouse(Camera& cam, RayCollision& collision, Ray& ray)
	{

		if (IsCursorHidden()) UpdateCamera(&cam, CAMERA_THIRD_PERSON);

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
	}
	void RenderInterface::calculatePosition(Camera cam, Vector3 CubePosition)
	{
		cubeScreenPosition0 = GetWorldToScreen(Vector3{ 0.0f, 0.0f, CubePosition.z }, cam);
		cubeScreenPositionX = GetWorldToScreen(Vector3{ 1.0f, 30.0f, CubePosition.z }, cam);
		cubeScreenPosition0X = GetWorldToScreen(Vector3{ 0.0f, -20.0f, CubePosition.z }, cam);
		cubeScreenPositionZ = GetWorldToScreen(Vector3{ 30.0f,0.5f, CubePosition.z }, cam);
		cubeScreenPosition0Z = GetWorldToScreen(Vector3{ -30.0f,0.5f, CubePosition.z }, cam);
		cubeScreenPositionY = GetWorldToScreen(Vector3{ 0.5f, 0.5f, 30.0f }, cam);
		cubeScreenPosition0Y = GetWorldToScreen(Vector3{ 0.5f, 0.5f, -30.0f }, cam);

	}
	void RenderInterface::Draw3DLine()
	{
		DrawLine3D({ 0.0f, -20.0f, 0.0f }, { 0.0f, 30.0f, 0.0f }, DARKGRAY);
		DrawGrid(30, 2.0f);

	}
	
	void RenderInterface::DrawAllCurves(containercurves::ContainerCurves& container)
	{
		const auto& allPoints = container.getPoints();
		const auto& curves = container.getContainer();

		for(int i = 0; i < curves.size(); i++)
		{
			const auto& curvePoints = allPoints[i];
			const auto& color = curves[i]->getColor();
			if (curvePoints.size() < 2) continue;

			for (int j = 0; j < curvePoints.size() - 1; j++)
			{
				DrawLine3D(curvePoints[j], curvePoints[j + 1], color);
			}
		}
	}
	void RenderInterface::Draws3DText()
	{
		DrawText("0", (int)cubeScreenPosition0.x, (int)cubeScreenPosition0.y, 15, BLACK);
		DrawText("X", (int)cubeScreenPositionX.x, (int)cubeScreenPositionX.y, 20, BLACK);
		DrawText("-X", (int)cubeScreenPosition0X.x, (int)cubeScreenPosition0X.y, 20, BLACK);
		DrawText("Y", (int)cubeScreenPositionY.x, (int)cubeScreenPositionY.y, 20, BLACK);
		DrawText("-Y", (int)cubeScreenPosition0Y.x, (int)cubeScreenPosition0Y.y, 20, BLACK);
		DrawText("Z", (int)cubeScreenPositionZ.x, (int)cubeScreenPositionZ.y, 20, BLACK);
		DrawText("-Z", (int)cubeScreenPosition0Z.x, (int)cubeScreenPosition0Z.y, 20, BLACK);
	}

	//void RenderInterface::DrawSearch()
	//{
	//	int result = GuiTextInputBox(Rectangle{ 350, 9, 400, 110 },
	//	"Imput Box", 0, "Ok;Censel", buffer, 1024, 0);
	//	if (result >= 0) showMessageBox3 = false;
	//}
}