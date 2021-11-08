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

int sudoku[10][10];

bool check_row[9][10]; //행
bool check_col[9][10]; //열
bool square[9][10]; // 33검사

int get_square(int row, int col) {
    return (row / 3) * 3 + (col / 3);
}

bool solve(int num) {
    if (num == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }


    int x = num / 9; int y = num % 9;

    if (sudoku[x][y]) {

        return solve(num + 1);
    }
    else {

        for (int i = 1; i <= 9; i++) {
            if (!check_row[x][i] && !check_col[y][i] && !square[get_square(x, y)][i]) {

                check_row[x][i] = true;
                check_col[y][i] = true;
                square[get_square(x, y)][i] = true;
                sudoku[x][y] = i;

                if (solve(num + 1)) {
                    return true;
                }

                check_row[x][i] = false;
                check_col[y][i] = false;
                square[get_square(x, y)][i] = false;
                sudoku[x][y] = 0;
            }
        }
    }

    return false;
}

int main(void) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];

            if (sudoku[i][j]) {
                check_row[i][sudoku[i][j]] = true;
                check_col[j][sudoku[i][j]] = true;
                square[get_square(i, j)][sudoku[i][j]] = true;
            }
        }
    }
    solve(0);
    return 0;
}