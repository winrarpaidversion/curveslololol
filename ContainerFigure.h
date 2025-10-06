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
	std::vector<std::shared_ptr<Curve>> container;

public:

	void LevelContainer(int index)
	{
		for (auto& fig : container)
		{
			fig->Draw();
		}
	
	};
};

