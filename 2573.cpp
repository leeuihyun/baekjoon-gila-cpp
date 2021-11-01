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
#define MAX 100001
using namespace std;

int n;
int answer = 0;
int board[15];
int promise(int number);
void nqueen(int number);
int main() {
	cin >> n;
	nqueen(0);
	printf("%d", answer);
	return 0;
}
int promise(int number) {
	for (int i = 0; i < number; i++) {
		if (board[number] == board[i] || number - i == abs(board[number] - board[i])) { //대각선이나 같은라인이면 0
			return 0;
		}
	}
	return 1;
}
void nqueen(int number) {
	if (number == n) {
		answer++;
		return;
	}
	for (int i = 0; i < n; i++) {
		board[number] = i;
		if (promise(number)) {
			nqueen(number + 1);
		}
	}
}


