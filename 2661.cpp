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
int num;
int answer;
int arr[81];
string t = "";
bool ufind = false;
void solve(int cur, string s) { //cur == 현재 배열값에 넣고 있는 위치
	if (ufind == true) return;
	if (cur > number) return;
	int len = s.size();
	for (int i = 1; i <= (len / 2); i++) {
		string a = s.substr(len - i, i);
		string b = s.substr(len - (2 * i), i);
		if (a == b) {
			s = "";
			return;
		}
	}
	if (cur == number) {
		ufind = true;
		cout << s;
		return;
	}
	else {
		for (int i = 0; i < number; i++) {
			solve(cur + 1, s + "1");
			solve(cur + 1, s + "2");
			solve(cur + 1, s + "3");
		}
	}
}

int main() {
	cin >> number;
	solve(0, t);
	return 0;
}