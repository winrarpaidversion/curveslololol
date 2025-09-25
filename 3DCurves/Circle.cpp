#include "Circle.h"

Vector3 Circle::getPoint(double t)
{
	return { radius * std::cos(t), radius * std::sin(t), 0.0};
}

Vector3 Circle::getDerivative(double t)
{
	return { -radius * std::sin(t), radius * std::cos(t), 0.0};
}
