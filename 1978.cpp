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
#define MAX 1001
using namespace std;

int number;
int ans = 0;
int main() {
	cin >> number;
	vector <bool> v(MAX + 1);
	v[1] = true;
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (v[i]) continue;
		for (int j = i * 2; j <= MAX; j += i) {
			v[j] = true;
		}
	}
	for (int i = 0; i < number; i++) {
		int n;
		cin >> n;
		if (!v[n]) ans++;
		else continue;
	}

	cout << ans;
	return 0;
}