#include "ContainerCurves.h"
namespace containercurves
{
	void ContainerCurves::initializeContainers()
	{
		//container.resize(2);
		//container[0].push_back(std::make_shared<Cube>(1.0f, 1.0f, 1.0f, RED));
		//container[1].push_back(std::make_shared<Ellips>(10.0f, 10.0f, 10.0f,10.0f,10.0f, RED));
			//container[2].push_back(std::make_shared<Helix>(0, 0, 0));
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
	void ContainerCurves::DrawCurrentContainer()
	{
		if (CurrentLevel >= 0 && CurrentLevel < container.size())
		{
			for (auto& fig : container[CurrentLevel])
			{
				//fig->Draw();
			}
		}
	}
}