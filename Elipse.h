#pragma once
class Elipse : public Curve
{
private:
	int x;
	int y;
	float z;
	float a;
	float c;
public:
	Elipse(int x, int  y, float z, float a, float c) : x{ x }, y{ y }, z{ z } , a{a}, c{c}
	{
	};

	
	Vector GetPoint(float t) override;
	Vector GetDerivatives(float t) override;
	//bool isEquals(Curve& curve)
	//{
	//};
	void Draw()
	{

		DrawEllipse(x, y, z, a, RED);
	}
};

