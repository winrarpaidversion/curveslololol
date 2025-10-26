#pragma once
#include"Curve.h"
class Ellipse : public Curve
{
public:
	Ellipse(Vector3 center, float radius, float a, float b, std::string name) : center{ center }, radius{ radius }, name{ name }, a{ a }, b{ b } {}

	Vector3 center;
	float radius;
	float a;
	float b;
	std::string name;


	Vector3 getPoint(float t) override;

	Vector3 getDerivative(float t) override;

	Vector3 getCenter();
	float getRadius();
	std::string getName();
};

