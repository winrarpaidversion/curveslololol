#include "ContainerCurves.h"
namespace containercurves
{
	void ContainerCurves::initializeContainers()
	{
		container.push_back(std::make_shared<Ellipse>(Vector3{ 1,1,1 }, 25, 20, 10, "Ellipse", BLACK));
	/*	container.push_back(std::make_shared<Circle>(Vector3{ 1,1,1 }, 25, "Circle", BLACK, 25, 45, 50));
		container.push_back(std::make_shared<Helix>(Vector3{ 1,1,1 }, 25, 5, "Helix", BLACK, 25, 45, 50));
		container.push_back(std::make_shared<Circle>(Vector3{ 10,0,0 }, 25, "Circle1", BLACK, 25, 45, 50));
		container.push_back(std::make_shared<Circle>(Vector3{ 20,0,0 }, 25, "Circl", BLACK , 25, 45, 50));
		container.push_back(std::make_shared<Circle>(Vector3{ 10,0,0 }, 25, "Circle3", BLACK, 25, 45, 50));*/
	}

	void ContainerCurves::AddCurve(std::shared_ptr<Curve> curve)
	{
		container.push_back(curve);
		updatePoints();
		findCircles();
	}
	void ContainerCurves::updatePoints()
	{
		int segments = 200;
		points.clear();

		for (auto& curve : container)
		{
			std::vector<Vector3> curvePoints;

			float mT = 2 * PI;

			for (int i = 0; i <= segments; i++)
			{
				float t = mT * i / segments;
				curvePoints.push_back(curve->getPoint(t));
			}

			points.push_back(curvePoints);
			std::cout << "Container size: " << container.size() << " Points: " << points.size() << "\n";
		}
	}
	void ContainerCurves::findCircles()
	{
		circleContainer.clear();
		for (auto& circle : container)
		{
			if (circle->getClass() == "Circle")
			{
				circleContainer.push_back(circle);
			}
		}
	}
	void ContainerCurves::NextCurve()
	{
		if (CurrentLevel < container.size() - 1)
		{
			CurrentLevel++;
		}
		else if (container.size() > CurrentLevel)
		{
			CurrentLevel = 0;
		};
	}
	void ContainerCurves::PrevCurve()
	{
		if (CurrentLevel > 0)
		{
			CurrentLevel--;
		}
		else
		{
			CurrentLevel = container.size() - 1;
		};

	}
	const std::vector<std::shared_ptr<Curve>>& ContainerCurves::getContainer()
	{
		return container;
	}

	const std::vector<std::shared_ptr<Curve>>& ContainerCurves::getCircleContainer()
	{
		return circleContainer;
	}

	const std::vector<std::vector<Vector3>>& ContainerCurves::getPoints()
	{
		return points;
	}

}