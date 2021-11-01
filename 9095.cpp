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
#define MAX 100001
using namespace std;

int n;
int dp[12];

int solve(int number) {
	if (number == 0) return 1;
	if (number == 1) return 1;
	if (number == 2) return 2;
	if (dp[number]) return dp[number];
	dp[number] = solve(number - 1) + solve(number - 2) + solve(number - 3);
	return dp[number];
}

int main() {
	cin >> n;
	while (n--) {
		int n;
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}