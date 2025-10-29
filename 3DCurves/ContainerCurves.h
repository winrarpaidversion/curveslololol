#pragma once
#include <vector>
#include "Curve.h"
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

		
	};
};

