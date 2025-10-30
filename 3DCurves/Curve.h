#pragma once
#include <cmath>
#include <string>
#include <raylib.h>


class Curve
{
public:
	virtual ~Curve() = default;
	virtual Vector3 getPoint(float t) = 0;
	virtual Vector3 getDerivative(float t) = 0;
	virtual std::string getName() = 0;
	virtual Color getColor() = 0;
	virtual std::string getClass() = 0;
	virtual float getRadius() = 0;
};

