#include "Figure.h"
#include "Circle.h"
#include "Ball.h"

#include <string>
#include <iostream>

using namespace std;

Ball::Ball(string name, int radius) :Circle(name, radius)
{
	type = "volume";
}
double Ball::getArea()
{
	return 4 * pi * radius * radius;
}
double Ball::getVolume()
{
	return 4 / 3 * pi * radius * radius * radius;
}