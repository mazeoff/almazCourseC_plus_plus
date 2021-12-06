#pragma once
//#include <string>

//using namespace std;

class Figure
{
protected:
	string name;
	string type;
public:

	Figure(string name);
	string getName();
	void getType();

	void showArea(int area);
	void showPerimeter(int perimeter);
	void showVolume(int volume);

	virtual double getPerimeter() = 0;
	virtual double getArea() = 0;
};