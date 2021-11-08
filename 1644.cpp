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
int cnt;
const int MAX_NUM = 4000000;
int arr[MAX_NUM + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 2; i <= MAX_NUM; i++)arr[i] = i;
	for (int i = 2; i <= sqrt(MAX_NUM); i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= MAX_NUM; j += i)
			arr[j] = 0;
	}
	cin >> number;
	if (number == 1) {
		cout << 0 << endl;
		exit(0);
	}
	for (int i = 2; i <= number; i++) {
		if (!arr[i])continue;
		int sum = 0;
		for (int j = i; j <= number; j++) {
			sum += arr[j];
			if (sum > number)break;
			else if (sum == number) {
				cnt++;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}