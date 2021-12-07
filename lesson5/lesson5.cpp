#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#include "Figure.h"
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Cube.h"
#include "Ball.h"


using namespace std;

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