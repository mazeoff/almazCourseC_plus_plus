#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Figure
{
protected:
	string name;
	string type;
public:
	Figure(string name)
	{
		this->name = name;
		this->type = type;
	}
	string getName()
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
		if(type == "flat")
			cout << "Perimeter of " << name << " = " << perimeter << endl;
		else
			cout << "Error! Impossible to find the perimeter in "<< name << endl;
	}
	void showVolume(int volume) {
		if (type == "volume")
			cout << "Volume of " << name << " = " << volume << endl;
		else
			cout << "Error! Impossible to find the volume in "<< name << endl;
	}
};

class Square: public Figure 
{
protected:
	int lengthOfSide;
public:
	Square(string name, int lengthOfSide) :Figure(name)
	{
		this->lengthOfSide = lengthOfSide;
		type = "flat";
	}
	int getPerimeter() {
		return lengthOfSide * 4;
	}
	int getArea() {
		return pow(lengthOfSide,2);
	}
};

class Rectangle : public Figure
{
private:
	int sideA;
	int sideB;
public:
	Rectangle(string name, int sideA, int sideB) :Figure(name)
	{
		this->sideA = sideA;
		this->sideB = sideB;
		type = "flat";
	}
	int getPerimeter() {
		return sideA * 2 + sideB * 2;
	}
	int getArea() {
		return sideA * sideB;
	}
};

class Triangle : public Figure
{
private:
	int sideA;
	int sideB;
	int sideC;
public:
	Triangle(string name, int sideA, int sideB, int sideC) :Figure(name)
	{
		this->sideA = sideA;
		this->sideB = sideB;
		this->sideC = sideC;
		type = "flat";
	}
	int getPerimeter() {
		return sideA + sideB + sideC;
	}
	int getArea() {
		int p = getPerimeter()/2;
		return sqrt(p*(p - sideA)*(p - sideB)*(p - sideC));
	}
};

class Circle : public Figure
{
protected:
	const double pi = 3.1415926;
	int radius;
public:
	Circle(string name, int radius) :Figure(name)
	{
		this->radius = radius;
		type = "flat";
	}
	double getPerimeter() {
		return 2 * pi * radius;
	}
	int getArea() {
		return pi * radius * radius;
	}
};

class Cube : public Square
{
public:
	Cube(string name, int lengthOfSide) :Square(name, lengthOfSide)
	{
		type = "volume";
	}
	int getArea() {
		return Square::getArea()*6;
	}
	int getVolume() {
		return pow(lengthOfSide, 3);
	}
};

class Ball : public Circle
{
public:
	Ball(string name, int radius) :Circle(name, radius)
	{
		type = "volume";
	}
	int getArea() {
		return 4 * pi * radius * radius;
	}
	int getVolume() {
		return 4/3 * pi * radius * radius * radius;
	}

};


int main()
{

	///////Square////////////
	Square s("Square_1", 10);
	s.getType();
	s.showPerimeter(s.getPerimeter());
	s.showArea(s.getArea());
	cout << endl;

	///////Rectangle////////////
	Rectangle r("Rectangle_1", 3, 4);
	r.getType();
	r.showPerimeter(r.getPerimeter());
	r.showArea(r.getArea());
	cout << endl;

	///////Triangle////////////
	Triangle t("Triangle_1", 3, 4, 5);
	t.getType();
	t.showPerimeter(t.getPerimeter());
	t.showArea(t.getArea());
	cout << endl;

	///////Circle////////////
	Circle c("Circle_1", 3);
	c.getType();
	c.showPerimeter(c.getPerimeter());
	c.showArea(c.getArea());
	cout << endl;

	///////Cube////////////
	Cube cb("Cube_1", 3);
	cb.getType();
	cb.showArea(cb.getArea());
	cb.showVolume(cb.getVolume());
	cout << endl;

	///////Ball////////////
	Ball b("Ball_1", 3);
	b.getType();
	b.showArea(b.getArea());
	b.showVolume(b.getVolume());
	cout << endl;

}