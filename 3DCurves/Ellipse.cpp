#include "Ellipse.h"

Vector3 Ellipse::getPoint(float t)
{
	Vector3 p{ a * std::cos(t), b * std::sin(t), 0.0 };

	p = rotateX(p, angleX); p = rotateY(p, angleY); p = rotateZ(p, angleZ);

	p.x += center.x;
	p.y += center.y;
	p.z += center.z;

	return p;
}

Vector3 Ellipse::getDerivative(float t)
{
	Vector3 d{ -a * std::sin(t), b * std::cos(t), 0.0 };

	d = rotateX(d, angleX); d = rotateY(d, angleY); d = rotateZ(d, angleZ);

	return d;
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
// hmmmm
Vector3 Ellipse::rotateX(Vector3& v, float angle) {
	float cosA = std::cos(angle);
	float sinA = std::sin(angle);
	return {
		v.x,
		v.y * cosA - v.z * sinA,
		v.y * sinA + v.z * cosA };
}

Vector3 Ellipse::rotateY(Vector3& v, float angle) {
	float cosA = std::cos(angle);
	float sinA = std::sin(angle);
	return {
		v.x * cosA + v.z * sinA,
		v.y,
		-v.x * sinA + v.z * cosA };
}

Vector3 Ellipse::rotateZ(Vector3& v, float angle) {
	float cosA = std::cos(angle);
	float sinA = std::sin(angle);
	return {
		v.x * cosA - v.y * sinA,
		v.x * sinA + v.y * cosA,
		v.z };
}