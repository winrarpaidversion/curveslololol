#pragma once
#include"Curve.h"
class Circle : public Curve
{
public:
	Circle(Vector3 center, float radius, std::string name, Color color, float angleX = 0, float angleY = 0, float angleZ = 0) : center{ center }, radius{ radius }, 
		name{ name }, color{ color }, 
		angleX{ angleX }, angleY{ angleY }, angleZ{ angleZ } {}
	
	Vector3 center;
	float radius;
	std::string name;
	Color color;
	float angleX, angleY, angleZ;

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