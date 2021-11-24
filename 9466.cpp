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
int arr[100001];
bool visited[100001];
bool clear[100001];
int cnt = 0;

void solve(int number) {
	visited[number] = true;
	int next = arr[number];
	if (!visited[next]) {
		solve(next);
	}
	else if (!clear[next]) { //�湮�� true ������ ����Ŭ�� ������ ����.
		for (int i = next; i != number; i = arr[i]) {
			cnt++;
		}
		cnt++;
	}
	clear[number] = true;
}

int main() {
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		memset(visited, false, sizeof(visited));
		memset(clear, false, sizeof(visited));
		int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> arr[j];
		}
		cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				solve(j);
			}
		}
		cout << n - cnt << "\n";
	}
	return 0;
}