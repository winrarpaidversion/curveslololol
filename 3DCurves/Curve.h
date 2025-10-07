#pragma once
#include<cmath>
#include<string>

struct Vector3 {
	double x;
	double y;
	double z;
};

class Curve
{
public:
	virtual ~Curve() = default;
	virtual Vector3 getPoint(double t) = 0;
	virtual Vector3 getDerivative(double t) = 0;


};

