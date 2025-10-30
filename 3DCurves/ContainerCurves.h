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

		void initializeContainers();
		void NextCurve();
		void PrevCurve();
		void DrawCurrentContainer();
		void AddCurve(std::shared_ptr<Curve> curve);

		
		
	};
};

