#include "ContainerCurves.h"
namespace containercurves
{
	void ContainerCurves::initializeContainers()
	{
		container.push_back(std::make_shared<Circle>(Vector3{0,0,0}, 10, "mY CIRCLE", BLACK)); 
		container.push_back(std::make_shared<Circle>(Vector3{ 0,0,0 }, 10, "mY CIRCLE2", BLACK));
		container.push_back(std::make_shared<Circle>(Vector3{ 0,0,0 }, 10, "mY CIRCL3", BLACK));
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
	/*void ContainerCurves::DrawCurrentContainer()
	{
		if (CurrentLevel >= 0 && CurrentLevel < container.size())
		{
			for (auto& fig : container[CurrentLevel])
			{
				fig->Draw();
			}
		}
	}*/
}