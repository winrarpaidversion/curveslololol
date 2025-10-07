#pragma once
#include"Curve.h"
class Circle : public Curve
{
public:
	Circle(Vector3 center, double radius, std::string name) : center{ center }, radius{ radius }, name{ name } {}


	Vector3 center;
	double radius;
	std::string name;

	Vector3 getPoint(double t) override;

	Vector3 getDerivative(double t) override;


	Vector3 getCenter();

	double getRadius();
	std::string getName();
};