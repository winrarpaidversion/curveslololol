#pragma once
#include"Curve.h"
class Circle : public Curve
{
public:
	Vector3 center;
	double radius;

	Vector3 getPoint(double t) override;

	Vector3 getDerivative(double t) override;
};

// первый контейнер -> рандомные фигуры, все эти фигуры 
// должны возвращать точку и касательную
// 
// вывести точку и касательную всех фигур при t= PI/4

/*  Второй контейнер содержит только круги из первого контейнера через указатели

	( х 1 – х 0 ) ( х – х 0 ) + ( у 1 – у 0 ) ( у – у 0 ) = R^2 . 
*/
