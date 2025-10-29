#include "Circle.h"

Vector3 Circle::getPoint(float t)
{
	return { radius * std::cos(t), radius * std::sin(t), 0.0 };
}

Vector3 Circle::getDerivative(float t)
{
	return { -radius * std::sin(t), radius * std::cos(t), 0.0 };
}

Vector3 Circle::getCenter()
{
	return center;
}

float Circle::getRadius()
{
	return radius;
}

std::string Circle::getName()
{
	return name;
}

Color Circle::getColor()
{
	return color;
}

std::string Circle::getClass()
{
	return "Circle";
}
