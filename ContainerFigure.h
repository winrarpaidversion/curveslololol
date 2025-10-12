#pragma once
#include <list>
#include<vector>
#include<array>
#include "Curve.h"
#include "Cube.h"
#include "Elipse.h"
class ContainerFigure
{
private:
	std::vector<std::vector<std::shared_ptr<Curve>>> container;
	int CurrentLevel = 0;
public:
	void initializeContainers()
	{
		container.resize(4);
		container[0].push_back(std::make_shared<Cube>(3.0f, 3.0f, 3.0f, RED));
		container[1].push_back(std::make_shared<Elipse>(4.0f, 4.0f, 4.0f, 4.0f, 4.0f, BLUE));
	
		//container[2].push_back(std::make_shared<Helix>(0, 0, 0));

	}
	void NextCurve()
	{
		if (CurrentLevel < container.size() - 1)
		{
			CurrentLevel++;
		}
		else if(container.size() > CurrentLevel)
		{
			CurrentLevel = 0;
		};
	}
	void PrevCurve()
	{
		if (CurrentLevel > 0)
		{
			CurrentLevel--;
		}
		else
		{
			CurrentLevel = container.size() -1;
		};
	
	}
	void DrawCurrentContainer()
	{
		if (CurrentLevel >= 0 && CurrentLevel < container.size())
		{
			for (auto& fig : container[CurrentLevel])
			{
				fig->Draw();
			}
		}
	}
	int GetCurrentContainer()
	{
		return CurrentLevel;
	}
	int GetTotalContainer()
	{
		return container.size();
	}
	
};

