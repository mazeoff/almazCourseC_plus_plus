#include "classFigure.h"


Figure(string name)
{
	this->name = name;
	this->type = type;
}

string Figure::getName()
{
	return "Name: " + name;
}
void getType()
{
	cout << "Type of " << name << " is a " + type << endl;
}
void showArea(int area) {
	cout << "Area of " << name << " = " << area << endl;
}

void showPerimeter(int perimeter) {
	if (type == "flat")
		cout << "Perimeter of " << name << " = " << perimeter << endl;
	else
		cout << "Error! Impossible to find the perimeter in " << name << endl;
}
void showVolume(int volume) {
	if (type == "volume")
		cout << "Volume of " << name << " = " << volume << endl;
	else
		cout << "Error! Impossible to find the volume in " << name << endl;
}
