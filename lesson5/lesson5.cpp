#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#include "classFigure.h"

using namespace std;

//class Figure
//{
//protected:
//	string name;
//	string type;
//public:
//
//	Figure(string name)
//	{
//		this->name = name;
//		this->type = type;
//	}
//	string getName()
//	{
//		return "Name: " + name;
//	}
//	void getType()
//	{
//		cout << "Type of " << name << " is a " + type << endl;
//	}
//	void showArea(int area) {
//		cout << "Area of " << name << " = " << area << endl;
//	}
//
//	void showPerimeter(int perimeter) {
//		if (type == "flat")
//			cout << "Perimeter of " << name << " = " << perimeter << endl;
//		else
//			cout << "Error! Impossible to find the perimeter in " << name << endl;
//	}
//	void showVolume(int volume) {
//		if (type == "volume")
//			cout << "Volume of " << name << " = " << volume << endl;
//		else
//			cout << "Error! Impossible to find the volume in " << name << endl;
//	}
//
//	virtual double getPerimeter() = 0;
//	virtual double getArea() = 0;
//};

class Square : public Figure
{
protected:
	int lengthOfSide;
public:
	Square(string name, int lengthOfSide) :Figure(name)
	{
		this->lengthOfSide = lengthOfSide;
		type = "flat";
	}
	double getPerimeter() override
	{
		return lengthOfSide * 4;
	}
	double getArea() override
	{
		return pow(lengthOfSide, 2);
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
	double getPerimeter() override
	{
		return sideA * 2 + sideB * 2;
	}
	double getArea() override
	{
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
	double getPerimeter() override
	{
		return sideA + sideB + sideC;
	}
	double getArea() override
	{
		int p = getPerimeter() / 2;
		return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
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
	double getPerimeter() override
	{
		return 2 * pi * radius;
	}
	double getArea() override
	{
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
	double getArea() override
	{
		return Square::getArea() * 6;
	}
	double getVolume()
	{
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
	double getArea() override
	{
		return 4 * pi * radius * radius;
	}
	double getVolume()
	{
		return 4 / 3 * pi * radius * radius * radius;
	}

};


int main()
{
	/*
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

	*/
	////////////////////////////////
	string figureName;
	int lengthOfSide;
	int n;
	int maxArea = 0;
	cin >> n;
	Figure **figures = new Figure*[n];
	srand(time(0));
	for (int i = 0; i < n; i++) {
		switch (rand() % 6 + 1)
		{
		case 1:
			cout << "Enter name of figure (square): " << endl;
			cin >> figureName;
			cout << "Enter length of side: " << endl;
			cin >> lengthOfSide;
			figures[i] = new Square(figureName, lengthOfSide);
			break;
		case 2:
			figures[i] = new Rectangle("Rectangle_" + to_string(i), 3, 4);
			break;
		case 3:
			figures[i] = new Triangle("Triangle_" + to_string(i), 3, 4, 5);
			break;
		case 4:
			figures[i] = new Circle("Circle_" + to_string(i), 3);
			break;
		case 5:
			figures[i] = new Cube("Cube_" + to_string(i), 3);
			break;
		case 6:
			figures[i] = new Ball("Ball_" + to_string(i), 3);
			break;
		default:
			break;
		}

	}

	ofstream out("file.txt");

	for (int i = 0; i < n; i++) {
		out << "Area of " << figures[i]->getName() << " = " << figures[i]->getArea() << endl;
	}

	out << endl;

	for (int i = 0; i < n; i++) {
		if (i < n - 1) {
			if (figures[i]->getArea() > figures[i + 1]->getArea()) {
				swap(figures[i], figures[i + 1]);
				i = -1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		out << "Area of " << figures[i]->getName() << " = " << figures[i]->getArea() << endl;
	}

	out << endl;

	for (int i = n-1; i > 0; i--) {
		if(figures[i]->getArea() == figures[n - 1]->getArea()  )
			out << "Area of " << figures[i]->getName() << " = " << figures[i]->getArea() << endl;
	}



	out.close();
	delete [] figures;
}