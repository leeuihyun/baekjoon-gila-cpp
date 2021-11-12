#include<iostream>
#include<algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int cases;
int zero[41];
int one[41];

int  fibo_0(int number) {
	if (number == 0)
		return 1;
	else if (number == 1)
		return 0;
	if (zero[number])return zero[number];
	else {
		zero[number] = fibo_0(number - 1) + fibo_0(number - 2);
		return zero[number];
	}
}

int  fibo_1(int number) {
	if (number == 0)
		return 0;
	else if (number == 1)
		return 1;
	if (one[number])return one[number];
	else {
		one[number] = fibo_1(number - 1) + fibo_1(number - 2);
		return one[number];
	}
}

int main() {
	cin >> cases;
	while (cases--) {
		int number;
		cin >> number;
		cout << fibo_0(number) << " " << fibo_1(number) << "\n";
	}
	return 0;
}