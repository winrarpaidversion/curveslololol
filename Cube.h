#pragma once
#include "Curve.h"
#include <string>
class Cube : public Curve
{
private:
public:
	Cube(float x, float y, float z, Color color) : x{ x }, y{ y }, z{ z }, color{color} {};
	 float x;
	 float y;
	 float z;
	 Color color;
	Vector GetPoint(float t)override{ return Vector{ x, y, z }; }
	Vector GetDerivatives(float t) override{ return Vector{ 0.0f, 0.0f, 0.0f }; }
	bool IsEqual(const Curve& curve) const  override
	{
		const Cube* other = dynamic_cast<const Cube*>(&curve);
		if(!other)
		{
			return false;
		}
		return x == other->x && y == other ->y && z == other->z;

	};

	void Draw() override
	{
		DrawCube(Vector3{x,y,z }, 2.0f, 2.0f, 2.0f, color);
	}



};

