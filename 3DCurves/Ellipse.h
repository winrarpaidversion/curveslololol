#pragma once
#include"Curve.h"
class Ellipse : public Curve
{
public:
	Ellipse(Vector3 center, float radius, float a, float b, std::string name, Color color, float angleX = 0, float angleY = 0, float angleZ = 0) : center{ center }, radius{ radius }, name{ name },
		a{ a }, b{ b }, angleX{ angleX }, angleY(angleY), angleZ(angleZ), color{ color } {
	}

	Vector3 center;
	float radius;
	float a;
	float b;
	float angleX, angleY, angleZ;
	std::string name;
	Color color;

	Vector3 getPoint(float t) override;

	Vector3 getDerivative(float t) override;

	Vector3 getCenter();
	float getRadius();
	std::string getName() override;
	Color getColor() override;
	std::string getClass() override;

	Vector3 rotateX(Vector3& v, float angle);
	Vector3 rotateY(Vector3& v, float angle);
	Vector3 rotateZ(Vector3& v, float angle);
};
