#include <iostream>
#include <string>
#include "myVector.h"

using namespace std;

int main()
{

	MyVector<int> vec1;
	MyVector<int> vec2;
	vec1.push_back(10);
	vec1.push_back(20);
	vec1.push_back(30);
	vec1.reverse();
	vec1.show();
	cout << vec1.capacity() << endl;
	cout << vec1.size() << endl;
	vec1.shrink_to_fit();
	cout << vec1.capacity() << endl;
	cout << vec1.size() << endl;
}
