#include "ContainerCurves.h"
namespace containercurves
{
	void ContainerCurves::initializeContainers()
	{
		container.push_back(std::make_shared<Ellipse>(Vector3{ 1,1,1 }, 25, 20, 10, "Ellipse", WHITE, 25, 45, 50));
		container.push_back(std::make_shared<Circle>(Vector3{ 1,1,1 }, 25, "Circle", WHITE, 25, 45, 50));
		container.push_back(std::make_shared<Helix>(Vector3{ 1,1,1 }, 25, 5, "Helix", WHITE, 25, 45, 50));
	}

	void ContainerCurves::AddCurve(std::shared_ptr<Curve> curve)
	{
		container.push_back(curve);
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
	std::vector<std::shared_ptr<Curve>> ContainerCurves::getContainer()
	{
		return container;
	}

}