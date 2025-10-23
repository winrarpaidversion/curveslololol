#pragma once
#include<vector>
#include "Cube.h"
#include "Ellips.h"
#include <memory>
namespace containercurves 
{
	class ContainerCurves
	{
	private:
		std::vector<std::vector<std::shared_ptr<Curve>>> Container;
		std::vector<std::shared_ptr<Curve>>OnlyCircleContainer;
		int CurrentLevel = 0;
	public:
		void DrawCurrentContainer();
		void initializeContainers();
		void NextCurve();
		void ShareCircleContainer();
		void PrevCurve();
		void SortOnlyCircleContainer();



	


	};
};

