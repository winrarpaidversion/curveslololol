#include "Ellipse.h"

Vector3 Ellipse::getPoint(float t)
{
	return {a * std::cos(t), b * std::sin(t), 0.0};
}

Vector3 Ellipse::getDerivative(float t)
{
	return {-a * std::sin(t), b * std::cos(t), 0.0};
}

float Ellipse::getRadius()
{
	return radius;
}

std::string Ellipse::getName()
{
	return name;
}

Color Ellipse::getColor()
{
	return color;
}

std::string Ellipse::getClass()
{
	return "Ellipse";
}
