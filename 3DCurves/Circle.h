#pragma once
#include"Curve.h"
class Circle : public Curve
{
public:
	Circle(Vector3 center, float radius, std::string name) : center{ center }, radius{ radius }, name{ name } {}


	Vector3 center;
	float radius;
	std::string name;

	Vector3 getPoint(float t) override;

	Vector3 getDerivative(float t) override;


	Vector3 getCenter();

	float getRadius();
	std::string getName();
};