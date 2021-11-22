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
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int arr[1001][1001];
bool visited[1001][1001][2];

int answer;

int solve(int x, int y, int number, int result) { // x,y, 벽을 부실수 있는 횟수, 움직인 길이
	queue <pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(x, y), make_pair(number, result)));
	visited[x][y][1] = true;
	while (!q.empty()) {
		x = q.front().first.first;
		y = q.front().first.second;
		number = q.front().second.first;
		result = q.front().second.second;
		q.pop();
		if (x == n && y == m) return result;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m)continue;
			if (arr[nx][ny] && number == 1) {
				visited[nx][ny][number] = true;
				q.push(make_pair(make_pair(nx, ny), make_pair(number - 1, result + 1)));
			}
			if (!arr[nx][ny] && !visited[nx][ny][number]) {
				visited[nx][ny][number] = true;
				q.push(make_pair(make_pair(nx, ny), make_pair(number, result + 1)));
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	cout << solve(1, 1, 1, 1);

	return 0;
}