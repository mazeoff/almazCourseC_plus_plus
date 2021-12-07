#pragma once
#include <string>
using namespace std;

class Circle : public Figure
{
protected:
	const double pi = 3.1415926;
	int radius;
public:
	Circle(string name, int radius);
	double getPerimeter() override;
	double getArea() override;
};