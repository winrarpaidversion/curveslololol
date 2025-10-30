#pragma once
#include"Curve.h"
class Helix : public Curve
{
public:

	Helix(Vector3 center, float radius, float step, std::string name, float angleX = 0, float angleY = 0, float angleZ = 0) : center{ center }, radius{ radius }, name{ name }, step{ step },
		angleX{ angleX }, angleY{ angleY }, angleZ{ angleZ } {}

	Vector3 center;
	float radius;
	float step;
	float angleX, angleY, angleZ;
	std::string name;
	Color color;

	Vector3 getPoint(float t) override;

	Vector3 getDerivative(float t) override;

	Vector3 getCenter();
	float getRadius();
	float getStep();
	std::string getName() override;
	Color getColor() override;
	std::string getClass() override;

	Vector3 rotateX(Vector3& v, float angle);
	Vector3 rotateY(Vector3& v, float angle);
	Vector3 rotateZ(Vector3& v, float angle);
};

