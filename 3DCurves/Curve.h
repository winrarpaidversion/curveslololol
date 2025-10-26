#pragma once
#include<cmath>
#include<string>
#include <raygui.h>


class Curve
{
public:
	virtual ~Curve() = default;
	virtual Vector3 getPoint(float t) = 0;
	virtual Vector3 getDerivative(float t) = 0;


};

