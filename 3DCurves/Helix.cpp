#include "Helix.h"

Vector3 Helix::getPoint(float t)
{
	Vector3 p{ radius * std::cos(t), radius * std::sin(t), step * t };

	p = rotateX(p, angleX); p = rotateY(p, angleY); p = rotateZ(p, angleZ);

	p.x += center.x;
	p.y += center.y;
	p.z += center.z;

	return p;
}

Vector3 Helix::getDerivative(float t)
{
	Vector3 d{ -radius * std::sin(t), radius * std::cos(t), step };

	d = rotateX(d, angleX); d = rotateY(d, angleY); d = rotateZ(d, angleZ);

	return d;
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

Color Helix::getColor()
{
	return color;
}

std::string Helix::getClass()
{
	return "Helix";
}
Vector3 Helix::rotateX(Vector3& v, float angle)
{
	float cosA = std::cos(angle);
	float sinA = std::sin(angle);
	return {
		v.x,
		v.y * cosA - v.z * sinA,
		v.y * sinA + v.z * cosA };
}

Vector3 Helix::rotateY(Vector3& v, float angle)
{
	float cosA = std::cos(angle);
	float sinA = std::sin(angle);
	return {
		v.x * cosA + v.z * sinA,
		v.y,
		-v.x * sinA + v.z * cosA };
}

Vector3 Helix::rotateZ(Vector3& v, float angle)
{
	float cosA = std::cos(angle);
	float sinA = std::sin(angle);
	return {
		v.x * cosA - v.y * sinA,
		v.x * sinA + v.y * cosA,
		v.z };
}