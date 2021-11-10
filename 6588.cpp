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
//#define MAX 1000001
using namespace std;

int number;
const int MAX_NUM = 1000000;
int arr[MAX_NUM + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i <= MAX_NUM; i++)arr[i] = i;
	for (int i = 2; i <= sqrt(MAX_NUM); i++) {
		if (arr[i] == 0) continue;
		for (int j = i * i; j <= MAX_NUM; j += i) {
			arr[j] = 0;
		}
	}
	arr[2] = 0;
	while (1) {
		cin >> number;
		int tmp = number;
		if (number == 0) break;
		bool check = true;
		while (tmp--) {
			if (arr[tmp] && arr[number - tmp]) {
				cout << number << " = " << number - tmp << " + " << tmp << "\n";
				check = false;
				break;
			}
		}
		if (check) cout << "Goldbach's conjecture is wrong." << "\n";
	}
	return 0;
}