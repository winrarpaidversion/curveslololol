#pragma once
#include "Curve.h"
#include <string>
class Cube : public Curve
{
private:
public:
	Cube(float x, float y, float z) : x{ x }, y{ y }, z{ z } {};
	 float x;
	 float y;
	 float z;
	Vector GetPoint(float t) override;
	Vector GetDerivatives(float t) override;
	bool IsEqual(const Curve& curve) const  override
	{
		const Cube* other = dynamic_cast<const Cube*>(&curve);
		if(!other)
		{
			return false;
		}
		return x == other->x && y == other ->y && z == other->z;

	};

	void Draw() const override
	{
		DrawCube(Vector3{x,y,z }, 1.0f, 1.0f, 1.0f, RED);
	}



};

