#include "ContainerCurves.h"
namespace containercurves
{
	void ContainerCurves::initializeContainers()
	{
		Container.resize(3);
		Container[0].push_back(std::make_shared<Cube>(1.0f, 1.0f, 1.0f, RED));
		Container[1].push_back(std::make_shared<Ellips>(10.0f, 10.0f, 10.0f,10.0f,10.0f, RED));
			//container[2].push_back(std::make_shared<Helix>(0, 0, 0));
		ShareCircleContainer();

	}



	void ContainerCurves::SortOnlyCircleContainer()
	{
		for (int i = 0; i < OnlyCircleContainer.size(); i++)
		{
			for (int j = 0; j < OnlyCircleContainer.size() - 1; j++)
			{
				if (OnlyCircleContainer[j + 1] == OnlyCircleContainer[i + 1])
				{
					auto temp = OnlyCircleContainer[j + 1];
					OnlyCircleContainer[j + 1] = OnlyCircleContainer[j];
					OnlyCircleContainer[j] = temp;
				}
			}
		}
	}
	void ContainerCurves::ShareCircleContainer()
	{
		OnlyCircleContainer.clear();
		for (size_t i = 0; i < Container.size(); i++)
		{
			for (size_t j = 0; j < Container[i].size(); j++)
			{
				if (auto curle= std::dynamic_pointer_cast<Ellips>(Container[i][j]))
				{
					OnlyCircleContainer.push_back(curle);
				}

			}
		}
	}

	void ContainerCurves::NextCurve()
	{
		if (CurrentLevel < Container.size() - 1 || CurrentLevel < OnlyCircleContainer.size() -1)
		{
			CurrentLevel++;
		}
		else if (Container.size() > CurrentLevel)
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
			CurrentLevel = CurrentLevel ? Container.size() - 1 : CurrentLevel = OnlyCircleContainer.size() - 1;
		};

	}
	void ContainerCurves::DrawCurrentContainer()
	{
		if (CurrentLevel >= 0 && CurrentLevel < Container.size())
		{
			for (auto& fig : Container[CurrentLevel])
			{
				fig->Draw();
			}
		}
	}
}