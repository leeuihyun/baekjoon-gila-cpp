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
#define MAX 1000001
using namespace std;

int number;

int arr[21][21];
bool team[22];
int min_res = 1000000000;
void solve(int idx, int cnt) {
	if (idx == number / 2) {
		int start, link;
		start = 0;
		link = 0;
		for (int i = 1; i <= number; i++) {
			for (int j = 1; j <= number; j++) {
				if (team[i] == true && team[j] == true)start += arr[i][j];
				if (team[i] == false && team[j] == false)link += arr[i][j];
			}
		}
		min_res = min(min_res, abs(start - link));
		return;
	}
	for (int i = cnt; i < number; i++) {
		team[i] = true;
		solve(idx + 1, i + 1);
		team[i] = false;
	}
}
int main() {
	cin >> number;
	for (int i = 1; i <= number; i++) {
		for (int j = 1; j <= number; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, 1);
	cout << min_res;
	return 0;
}