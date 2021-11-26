#include <iostream>
using namespace std;

int pyramid(int n) {
	int sum = 0;
	int i = 0;
	while (sum < n) {
		i++;
		sum += i;
		if(n - sum < i + 1)
			return i;
	}
	return i;
}

int maxMultiple(int divisor, int bound)
{
	int num = 0;
	for (int i = 1; i <= bound; i++) {
		if (i % divisor == 0 && num < i) {
			num = i;
		}
	}
	return num;
}

int main()
{
	int divisor, bound;
	cin >> divisor >> bound;
	cout << maxMultiple(divisor, bound);
}