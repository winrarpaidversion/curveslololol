#pragma once

#include "raylib.h"
#include"raygui.h"
namespace RenderGui
{
	class RenderInterface
	{
	
	private:
		bool showMessageBox = false;
		bool showMessageBox2 = false;
		bool showMessageBox3 = false;
		Ray ray = { 0 };
		RayCollision collision = { 0 };
		Vector3 cubePosition = { 0.0f, 2.0f, 0.0f };
		Vector2 cubeScreenPosition0 = { 0.0f, 10.0f };
		Vector2 cubeScreenPositionX = { 0.0f, 10.0f };
		Vector2 cubeScreenPosition0X = { 0.0f, 10.0f };
		Vector2 cubeScreenPositionY = { 0.0f, 10.0f };
		Vector2 cubeScreenPosition0Y = { 0.0f, 10.0f };
		Vector2 cubeScreenPositionZ = { 0.0f, 10.0f };
		Vector2 cubeScreenPosition0Z = { 0.0f, 10.0f };
	public:
		void DrawExitMouse(Camera& Cam, RayCollision& Collision, Ray& Ray);
		void calculatePosition(Camera Cam, Vector3 CubePosition);
		void Draws3DText();
		void Draw3DLine();
		void DrawFrame();
		//void DrawSearch();
	

	};

}