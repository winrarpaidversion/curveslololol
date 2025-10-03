#pragma once
#include"Curve.h"
class Helix : public Curve
{
public:

	Helix(Vector3 center, double radius, double step, std::string name) : center{ center }, radius{ radius }, name{ name }, step{ step } {}

	Vector3 center;
	double radius;
	double step;
	std::string name;


	Vector3 getPoint(double t) override;

	Vector3 getDerivative(double t) override;

	Vector3 getCenter();
	double getRadius();
	double getStep();
	std::string getName();

};

