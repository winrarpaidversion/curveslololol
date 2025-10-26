#pragma once
#include"Curve.h"
class Helix : public Curve
{
public:

	Helix(Vector3 center, float radius, float step, std::string name) : center{ center }, radius{ radius }, name{ name }, step{ step } {}

	Vector3 center;
	float radius;
	float step;
	std::string name;


	Vector3 getPoint(float t) override;

	Vector3 getDerivative(float t) override;

	Vector3 getCenter();
	float getRadius();
	float getStep();
	std::string getName();

};

