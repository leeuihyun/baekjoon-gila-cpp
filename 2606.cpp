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

int n, m;
int arr[101][101];
bool visited[101];
int cnt;
void solve(int number) {
	queue <int> q;
	visited[number] = true;
	q.push(number);
	while (!q.empty()) {
		number = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[number][i] && !visited[i]) {
				q.push(i);
				visited[i] = true;
				cnt++;
			}
		}
	}
	//answer = cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	solve(1);
	cout << cnt;
	return 0;
}