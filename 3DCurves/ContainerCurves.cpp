#include "ContainerCurves.h"
namespace containercurves
{
	void ContainerCurves::initializeContainers()
	{
		container.push_back(std::make_shared<Circle>(Vector3{ 1,1,1 }, 25, "TestName"));
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