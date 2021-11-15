#include<iostream>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int dp[100001];

int n;

int solve(int number) {
	if (number == 1) return 0;
	if (dp[number]) return dp[number];
	int res = solve(number - 1) + 1;
	if (number % 3 == 0) {
		res = min(res, solve(number / 3) + 1);
	}
	if (number % 2 == 0) {
		res = min(res, solve(number / 2) + 1);
	}
	dp[number] = res;
	return dp[number];
}

int main() {
	cin >> n;
	cout << solve(n);
	return 0;
}