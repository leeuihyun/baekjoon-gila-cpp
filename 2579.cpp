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

int cases;

int dp[301];
int arr[301];

int main() {
	cin >> cases;
	for (int i = 1; i <= cases; i++) {
		cin >> arr[i];
	}
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	if (cases <= 2) {
		cout << dp[cases];
		return 0;
	}
	else {
		for (int i = 3; i <= cases; i++) {
			dp[i] = max(dp[i - 2], arr[i - 1] + dp[i - 3]) + arr[i];
		}
	}

	cout << dp[cases];
	return 0;
}