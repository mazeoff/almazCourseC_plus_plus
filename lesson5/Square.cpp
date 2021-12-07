#include "Figure.h"
#include "Square.h"

#include <string>
#include <iostream>

using namespace std;


Square::Square(string name, int lengthOfSide) :Figure(name)
{
	this->lengthOfSide = lengthOfSide;
	type = "flat";
}
double Square::getPerimeter()
{
	return lengthOfSide * 4;
}
double Square::getArea() 
{
	return pow(lengthOfSide, 2);
}