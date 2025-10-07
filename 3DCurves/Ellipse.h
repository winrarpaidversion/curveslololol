#pragma once
#include"Curve.h"
class Ellipse : public Curve
{
public:
	Ellipse(Vector3 center, double radius, double a, double b, std::string name) : center{ center }, radius{ radius }, name{ name }, a{ a }, b{ b } {}

	Vector3 center;
	double radius;
	double a;
	double b;
	std::string name;


	Vector3 getPoint(double t) override;

	Vector3 getDerivative(double t) override;

	Vector3 getCenter();
	double getRadius();
	std::string getName();
};

