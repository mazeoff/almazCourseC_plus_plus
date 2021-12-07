#pragma once
class Triangle : public Figure
{
private:
	int sideA;
	int sideB;
	int sideC;
public:
	Triangle(string name, int sideA, int sideB, int sideC);
	double getPerimeter() override;
	double getArea() override;
};