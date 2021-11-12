#include<iostream>
#include<algorithm>
#include<queue>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int n, m;
int answer;
bool visited[100001];

int solve(int start, int cnt) {
	queue<pair<int, int>> q;
	q.push({ start,cnt });
	visited[start] = true;
	while (!q.empty()) {
		start = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (start == m) return cnt;
		if (start - 1 >= 0 && !visited[start - 1]) {
			q.push({ start - 1, cnt + 1 });
			visited[start - 1] = true;
		}
		if (start + 1 < 100001 && !visited[start + 1]) {
			q.push({ start + 1,cnt + 1 });
			visited[start + 1] = true;
		}
		if (start * 2 < 100001 && !visited[start * 2]) {
			q.push({ start * 2, cnt + 1 });
			visited[start * 2] = true;
		}
	}
}

int main() {
	cin >> n >> m;
	cout << solve(n, 0);
	return 0;
}