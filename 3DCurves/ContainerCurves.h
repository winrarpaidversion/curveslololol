#pragma once
#include <vector>
#include "Curve.h"
#include <memory>
namespace containercurves 
{
	class ContainerCurves
	{
	private:
		
		int CurrentLevel = 0;
	public:
		std::vector<std::vector<std::shared_ptr<Curve>>> container;
		void initializeContainers();
		void NextCurve();
		void PrevCurve();
		void DrawCurrentContainer();

		
	};
};

