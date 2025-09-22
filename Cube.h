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





};

