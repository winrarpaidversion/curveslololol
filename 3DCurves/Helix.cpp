#include "Helix.h"

Vector3 Helix::getPoint(float t)
{
	return {radius * std::cos(t), radius * std::sin(t), step * t};
}

Vector3 Helix::getDerivative(float t)
{
	return {-radius * std::sin(t), radius * std::cos(t), };
}

float Helix::getRadius()
{
	return radius;
}

float Helix::getStep()
{
	return step;
}

std::string Helix::getName()
{
	return name;
}