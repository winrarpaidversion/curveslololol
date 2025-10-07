#include "Ellipse.h"

Vector3 Ellipse::getPoint(double t)
{
	return {a * std::cos(t), b * std::sin(t), 0.0};
}

Vector3 Ellipse::getDerivative(double t)
{
	return {-a * std::sin(t), b * std::cos(t), 0.0};
}

double Ellipse::getRadius()
{
	return radius;
}

std::string Ellipse::getName()
{
	return name;
}
