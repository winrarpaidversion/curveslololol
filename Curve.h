#pragma once
#include<cmath>
#include<vector>
struct Vector {
	float x;
	float y;
	float z;
};
class Curve
{
public:

	virtual ~Curve() = default;
	virtual Vector GetPoint(float t) =0;
	virtual Vector GetDerivatives(float t)=0;

	

};

