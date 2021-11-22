#include<iostream>
#include<algorithm>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int cases;

int dp[1001][3];

int answer;

int main() {
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> dp[i][j];
		}
	}
	for (int i = 1; i < cases; i++) {
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}

	answer = min(dp[cases - 1][0], min(dp[cases - 1][1], dp[cases - 1][2]));
	cout << answer;

	return 0;
}