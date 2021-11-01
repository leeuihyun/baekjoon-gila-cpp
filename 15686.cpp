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
int arr[51][51];
bool visited[51];
vector <pair<int, int>> house;
vector < pair<int, int>> chicken;
int answer = 987654321;
void dfs(int current_number, int cnt) {
	if (current_number > chicken.size()) return;
	if (cnt == m) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int distance = 987654321;
			for (int j = 0; j < chicken.size(); j++) {
				if (visited[j]) {
					int xd = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
					distance = min(distance, xd);
				}

			}
			sum += distance;
		}
		answer = min(answer, sum);
		return;
	}
	visited[current_number] = true;
	dfs(current_number + 1, cnt + 1);
	visited[current_number] = false;
	dfs(current_number + 1, cnt);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (arr[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}
	dfs(0, 0);
	cout << answer;
	return 0;
}
