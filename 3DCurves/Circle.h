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

// ������ ��������� -> ��������� ������, ��� ��� ������ 
// ������ ���������� ����� � �����������
// 
// ������� ����� � ����������� ���� ����� ��� t= PI/4

/*  ������ ��������� �������� ������ ����� �� ������� ���������� ����� ���������

	( � 1 � � 0 ) ( � � � 0 ) + ( � 1 � � 0 ) ( � � � 0 ) = R^2 . 
*/
