#include<iostream>
#include<algorithm>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int n, m, start;
int arr[1001][1001];
bool visited[1001];

void dfs(int number) {
	cout << number << " ";
	visited[number] = true;
	for (int i = 1; i <= n; i++) {
		if (arr[number][i] && !visited[i]) {
			dfs(i);
		}
	}
}
void bfs(int number) {
	queue<int> q;
	visited[number] = true;
	q.push(number);
	while (!q.empty()) {
		number = q.front();
		cout << number << " ";
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && arr[number][i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(start);
	cout << "\n";
	memset(visited, false, sizeof(visited));
	bfs(start);
	cout << "\n";
	return 0;
}