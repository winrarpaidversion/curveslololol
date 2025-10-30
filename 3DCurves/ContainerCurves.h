#pragma once
#include <vector>
#include "Circle.h"
#include <memory>
#include"Ellipse.h"
#include"Helix.h"
namespace containercurves 
{
	class ContainerCurves
	{
	public:

		std::vector<std::shared_ptr<Curve>> container;
		int CurrentLevel = 0;
		void AddCurve(float x, float y, float z, float a, float b,float step, float radius,float corner, std::string name, Color color);
		void initializeContainers();
		void NextCurve();
		void PrevCurve();
		void DrawCurrentContainer();

		
	};
};

