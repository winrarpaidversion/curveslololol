#include "Helix.h"

Vector3 Helix::getPoint(double t)
{
	return {radius * std::cos(t), radius * std::sin(t), step * t};
}

Vector3 Helix::getDerivative(double t)
{
	return {-radius * std::sin(t), radius * std::cos(t), };
}

double Helix::getRadius()
{
	return radius;
}

double Helix::getStep()
{
	return step;
}

std::string Helix::getName()
{
	return name;
}