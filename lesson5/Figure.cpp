#include "Figure.h"

#include <string>
#include <iostream>

using namespace std;


Figure::Figure(string name)
{
	this->name = name;
	//this->type = type;
}

string Figure::getName()
{
	return "Name: " + name;
}
void Figure::getType()
{
	cout << "Type of " << name << " is a " + type << endl;
}
void Figure::showArea(int area) {
	cout << "Area of " << name << " = " << area << endl;
}

void Figure::showPerimeter(int perimeter) {
	if (type == "flat")
		cout << "Perimeter of " << name << " = " << perimeter << endl;
	else
		cout << "Error! Impossible to find the perimeter in " << name << endl;
}
void Figure::showVolume(int volume) {
	if (type == "volume")
		cout << "Volume of " << name << " = " << volume << endl;
	else
		cout << "Error! Impossible to find the volume in " << name << endl;
}
