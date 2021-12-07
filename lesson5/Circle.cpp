#include "Figure.h"
#include "Circle.h"

#include <string>
#include <iostream>

using namespace std;


Circle::Circle(string name, int radius) :Figure(name)
{
	this->radius = radius;
	type = "flat";
}
double Circle::getPerimeter()
{
	return 2 * pi * radius;
}
double Circle::getArea()
{
	return pi * radius * radius;
}
