#pragma once

#include <string>
using namespace std;

class Ball : public Circle
{
public:
	Ball(string name, int radius);
	double getArea() override;
	double getVolume();
};