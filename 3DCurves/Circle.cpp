#include "Circle.h"

Vector3 Circle::getPoint(float t)
{
	Vector3 p{ 
		radius * std::cos(t), 
		radius * std::sin(t), 
		0.0 };
	
	p = rotateX(p, angleX); p = rotateY(p, angleY); p = rotateZ(p, angleZ);

	p.x += center.x;
	p.y += center.y;
	p.z += center.z;

	return p;
}

Vector3 Circle::getDerivative(float t)
{
	Vector3 d { 
		-radius * std::sin(t), 
		radius * std::cos(t), 
		0.0 };

	d = rotateX(d, angleX); d = rotateY(d, angleY); d = rotateZ(d, angleZ);
	
	return d;
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

Vector3 Circle::rotateX(Vector3& v, float angle)
{
	float cosA = std::cos(angle);
	float sinA = std::sin(angle);
	return { 
		v.x, 
		v.y * cosA - v.z * sinA,
		v.y * sinA + v.z * cosA };
}

Vector3 Circle::rotateY(Vector3& v, float angle)
{
	float cosA = std::cos(angle);
	float sinA = std::sin(angle);
	return { 
		v.x * cosA + v.z * sinA, 
		v.y, 
		-v.x * sinA + v.z * cosA };
}

Vector3 Circle::rotateZ(Vector3& v, float angle)
{
	float cosA = std::cos(angle);
	float sinA = std::sin(angle);
	return { 
		v.x * cosA - v.y * sinA,
		v.x * sinA + v.y * cosA,
		v.z };
}