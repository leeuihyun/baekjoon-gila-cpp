#include<iostream>
#include<algorithm>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

const long long MAX_NUM = 1000000;

long long min_number, max_number;
long long arr[MAX_NUM + 1];

int main() {
	cin >> min_number >> max_number;
	int cnt = 0;

	for (long long i = 2; i * i <= max_number; i++) {
		long long number = min_number / (i * i);

		if (min_number % (i * i)) numbder++;

		while (number * i * i <= max_number) {
			arr[number * i * i - min_number] = 1;
			number++;
		}
	}
	for (int i = 0; i <= max_number - min_number; i++) {
		if (arr[i] == 0)cnt++;
	}
	cout << cnt;
	return 0;
}