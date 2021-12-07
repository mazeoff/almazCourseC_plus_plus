#pragma once
#include <string>
using namespace std;

class Rectangle : public Figure
{
private:
	int sideA;
	int sideB;
public:
	Rectangle(string name, int sideA, int sideB);
	double getPerimeter() override;
	double getArea() override;
};