#include<iostream>
#include<algorithm>
#include<cstring>
#include <string>
#include<math.h>
#include<vector>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000001
using namespace std;

int cases;
int answer;
int cnt = 0;
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	cin >> cases;
	vector <int> v;

	for (int i = 0; i < cases; i++) {
		int number;
		cin >> number;
		v.push_back(number);
	}
	sort(v.begin(), v.end());
	vector <int> result;
	for (int i = 0; i < cases - 1; i++) {
		int ans = v[i + 1] - v[i];
		result.push_back(ans);
	}
	answer = gcd(result[0], result[1]);
	for (int i = 2; i < result.size(); i++) {
		answer = gcd(answer, result[i]);
	}


	for (int i = 0; i < cases - 1; i++) {
		cnt += result[i] / answer - 1;
	}
	cout << cnt;
	return 0;
}