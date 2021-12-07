#pragma once
#include <string>
using namespace std;

class Square : public Figure
{
protected:
	int lengthOfSide;
public:
	Square(string name, int lengthOfSide);
	double getPerimeter() override;
	double getArea() override;
};