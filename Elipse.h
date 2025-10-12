#pragma once
#include "Curve.h"
class Elipse : public Curve
{
private:
	float x;
	float y;
	float z;
	float a;
	float b;
	Color color;
public:
	Elipse(float x, float y, float z, float a, float b, Color color) : x{ x }, y{ y }, z{ z }, a{ a }, b{ b }, color{ color } {};

	Vector GetPoint(float t) override
	{
		return Vector{ x + a * cos(t), y + b * sin(t), z };
	}
	Vector GetDerivatives(float t) override
	{
		return Vector{ -a * sin(t), b * cos(t), 0.0f };
	}
	bool IsEqual(const Curve& curve) const override
	{
		const Elipse* other = dynamic_cast<const Elipse*>(&curve);
		if (!other)
		{
			return false;
		}
		return x == other->x && y == other->y && z == other->z && a == other->a && b == other->b;


	};
	void Draw() override
	{
		for (float t = 0; t < 2 * PI; t += 0.1f)
		{
			Vector point = GetPoint(t);
			DrawCube(Vector3{ point.x,point.y,point.z }, 3.0f, 3.0f, 3.0f, color);
		}

	};

	Color GetColor() const { return color; }



};