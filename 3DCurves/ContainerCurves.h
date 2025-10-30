#pragma once
#include <vector>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <memory>
#include <iostream>
namespace containercurves 
{
	class ContainerCurves
	{
	public:
		std::vector<std::shared_ptr<Curve>> container;
		std::vector<std::vector<Vector3>> points;
		std::vector<std::shared_ptr<Curve>> circleContainer;
		int CurrentLevel = 0;

		void initializeContainers();
		void NextCurve();
		void PrevCurve();
		
		const std::vector<std::shared_ptr<Curve>>& getContainer();
		const std::vector<std::shared_ptr<Curve>>& getCircleContainer();
		const std::vector<std::vector<Vector3>>& getPoints();
		void AddCurve(std::shared_ptr<Curve> curve);
		void updatePoints();


		void findCircles();
	};
};

