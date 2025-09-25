#pragma once
#include"Curve.h"
class Helix : public Curve
{
public:
	double radius;
	double step;

	Vector3 getPoint(double t) override;

	Vector3 getDerivative(double t) override;
};

