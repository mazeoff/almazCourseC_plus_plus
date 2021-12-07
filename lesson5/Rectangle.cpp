#include "Figure.h"
#include "Rectangle.h"

#include <string>

using namespace std;

Rectangle::Rectangle(string name, int sideA, int sideB) :Figure(name)
{
	this->sideA = sideA;
	this->sideB = sideB;
	type = "flat";
}
double Rectangle::getPerimeter() 
{
	return sideA * 2 + sideB * 2;
}
double Rectangle::getArea() 
{
	return sideA * sideB;
}