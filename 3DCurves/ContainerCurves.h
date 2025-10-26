#pragma once
#include<vector>
#include"Curve.h"
#include <memory>
namespace containercurves 
{
	class ContainerCurves
	{
	private:
		std::vector<std::vector<std::shared_ptr<Curve>>> container;
		int CurrentLevel = 0;
	public:
		
		void initializeContainers();
		void NextCurve();
		void PrevCurve();
		void DrawCurrentContainer();


	};
};

