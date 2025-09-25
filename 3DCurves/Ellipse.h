#pragma once
#include"Curve.h"
class Ellipse : public Curve
{
public:
	double a;
	double b;

	Vector3 getPoint(double t) override;

	Vector3 getDerivative(double t) override;
};

