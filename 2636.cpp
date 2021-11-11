#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<malloc.h>
#include<deque>
#include<stack>
#include<queue>
#include <cmath>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int arr[101][101];
bool visited[101][101];
int time1, res;
int n, m;

bool solve() {
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	time1++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (arr[nx][ny] == 0 && !visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
			else if (arr[nx][ny] == 1 && !visited[nx][ny]) {
				arr[nx][ny] = 0;
				cnt++;
				visited[nx][ny] = true;
			}
		}
	}
	if (cnt == 0) {
		cout << --time1 << "\n" << res;
		return true;
	}
	else {
		res = cnt;
		return false;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (true) {
		if (solve())
			break;
		memset(visited, false, sizeof(visited));
	}
	return 0;
}