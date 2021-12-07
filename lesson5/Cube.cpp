#include "Figure.h"
#include "Square.h"
#include "Cube.h"

#include <string>
#include <iostream>

using namespace std;

Cube::Cube(string name, int lengthOfSide) :Square(name, lengthOfSide)
{
	type = "volume";
}
double Cube::getArea()
{
	return Square::getArea() * 6;
}
double Cube::getVolume()
{
	return pow(lengthOfSide, 3);
}

