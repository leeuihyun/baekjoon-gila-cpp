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

int number;

int main() {
	cin >> number;
	vector <int> v;
	int ans;
	for (int i = 0; i < number; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	sort(v.begin(), v.end());
	if (v.size() == 1) {
		ans = v[0] * v[0];
	}
	else {
		ans = v.front() * v.back();
	}
	cout << ans;

	return 0;
}