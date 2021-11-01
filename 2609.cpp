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

int n, m;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int lcd(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	cin >> n >> m;
	cout << gcd(n, m) << "\n";
	cout << lcd(n, m) << "\n";
	return 0;
}