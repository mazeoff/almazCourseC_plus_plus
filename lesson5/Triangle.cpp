#include "Figure.h"
#include "Triangle.h"

#include <string>
#include <iostream>

using namespace std;

Triangle::Triangle(string name, int sideA, int sideB, int sideC) :Figure(name)
{
	this->sideA = sideA;
	this->sideB = sideB;
	this->sideC = sideC;
	type = "flat";
}
double Triangle::getPerimeter()
{
	return sideA + sideB + sideC;
}
double Triangle::getArea()
{
	int p = getPerimeter() / 2;
	return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}