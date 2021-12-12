#pragma once
#include <iostream>
using namespace std;

template <typename T> class MyVector {
private:
	T* vec;
	int cap;
	int vecSize;
public:
	MyVector()
	{
		vec = new T[1];
		cap = 1; 
		vecSize = 0;
	}
	void push_back(T val) {
		if (vecSize == cap) {
			T* temp = new T[2 * cap];
			for (int i = 0; i < vecSize; i++) {
				temp[i] = vec[i];
			}
			delete[] vec;
			cap *= 2;
			vec = temp;
		}
		vec[vecSize] = val;
		vecSize++;
	}
	void pop_back() {
		if (vecSize > 0) {
			vecSize--;
		}
	}
	T operator[](T index) {
		if (index < vecSize) {
			return vec[index];
		}
	}
	bool operator==(MyVector<T> secVec) {
		if (vecSize == secVec.vecSize) {
			for (int i = 0; i < vecSize; i++) {
				if (vec[i] != secVec[i]) {
					return false;
				}
			}
			return true;
		}
		else
			return false;
	}
	T front() {
		if ( vecSize > 0) {
			return vec[0];
		}
	}
	T back() {
		if (vecSize > 0) {
			return vec[vecSize];
		}
	}
	int begin() {
		if (vecSize > 0) {
			return 0;
		}
	}
	void end() {
		if (vecSize > 0) {
			return vecSize;
		}
	}
	void clear() {
		vecSize = 0;
	}
	void insert(int index, T val) {
		if (index == cap || index == vecSize) {
			push_back(val);
		}
		else {
			for (int i = vecSize-1; i >= index; i--) {
				vec[i + 1] = vec[i];
			}
			vec[index] = val;
			vecSize++;
			cap *= 2;
		}
	}
	void erase(int index) {
		if (vecSize > 0)
		{
			for (int i = index; i < vecSize; i++) {

				vec[i] = vec[i+1];
			}
			vecSize--;
		}
	}
	void revecSize(int value) {
		//cap += value;
		for (int i = vecSize; i < value; i++)
		{
			push_back(0);
		}
		//vecSize = value;
	}
	bool empty() {
		if (vecSize > 0)
			return false;
		else 
			return true;
	}
	void reverse() {
		MyVector<T> vecTwo;
		for (int i = vecSize-1; i >= 0; i--)
		{
			vecTwo.push_back(vec[i]);
		}
		for (int i = 0; i < vecSize; i++)
		{
			vec[i] = vecTwo[i];
		}
	}
	int capacity() {
		return cap;
	}
	int size() {
		return vecSize;
	}
	void shrink_to_fit() {
		if (vecSize != cap) {
			cap = vecSize;
		}
	}
	void show() {
		for (int i = 0; i < vecSize; i++) {
			cout << vec[i] << endl;
		}
	}
};