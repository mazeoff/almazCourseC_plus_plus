#pragma once
#include <string>
using namespace std;

class Cube : public Square
{
public:
	Cube(string name, int lengthOfSide);
	double getArea() override;
	double getVolume();
};