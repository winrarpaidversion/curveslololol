#pragma once
#include <vector>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <memory>
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
		std::vector<std::shared_ptr<Curve>> getContainer();
		void AddCurve(std::shared_ptr<Curve> curve);
	};
};

