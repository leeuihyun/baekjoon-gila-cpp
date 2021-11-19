#include<iostream>
#include<algorithm>
#include<cstring>
#include <string>
#include<math.h>
#include<vector>
#include<malloc.h>
#include<deque>
#include<stack>
#include<queue>
#include <sstream>
#include <functional>
#include <map>
#include <list>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int number;

int dp[501][501];

int main() {
	cin >> number;
	for (int i = 1; i <= number; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	int answer = dp[number][1];
	for (int i = 2; i <= number; i++) {
		answer = max(answer, dp[number][i]);
	}
	cout << answer << "\n";
	return 0;
}