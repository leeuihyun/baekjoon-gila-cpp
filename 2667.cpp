#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int number;
int arr[26][26];
bool visited[26][26];
int cnt; //전체개수
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
vector <int> v;

void bfs(int x, int y) {
	int res = 1;
	visited[x][y] = true;
	queue < pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= number || ny < 0 || ny >= number) continue;
			if (arr[nx][ny] && !visited[nx][ny]) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				res++;
			}
		}
	}
	v.push_back(res);
}

int main() {
	cin >> number;
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (arr[i][j] && !visited[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	return 0;
}