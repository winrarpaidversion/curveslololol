#pragma once
#include<vector>
#include "Curve.h"
#include "Cube.h"
#include "Elipse.h"
#include <memory>

	std::vector<std::vector<std::shared_ptr<Curve>>>container;
	int CurrentLevel = 0;
	void initializeContainers();
	void NextCurve();
	void PrevCurve();
	void DrawCurrentContainer();
	int GetCurrentContainer();
	int GetTotalContainer();

