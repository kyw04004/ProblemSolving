#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int R, C, N;
char board[6][201][201], chk[201][201];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C >> N;
	for (int i = 1; i <= R; i++) // 1초결과
		for (int j = 1; j <= C; j++)
			cin >> board[1][i][j];
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (board[1][i][j] == 'O') {
				chk[i][j] = 1;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
					chk[nx][ny] = 1;
				}
			}
	for (int i = 1; i <= R; i++) // 3초결과
		for (int j = 1; j <= C; j++) {
			if (chk[i][j]) board[3][i][j] = '.';
			else board[3][i][j] = 'O';
		}
	memset(chk, 0, sizeof(chk));
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (board[1][i][j] == '.' && board[3][i][j] == 'O') {
				chk[i][j] = 1;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
					chk[nx][ny] = 1;
				}
			}
	for (int i = 1; i <= R; i++) // 5초결과
		for (int j = 1; j <= C; j++) {
			if (chk[i][j]) board[5][i][j] = '.';
			else board[5][i][j] = 'O';
		}
	if (N == 1) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++)
				cout << board[1][i][j];
			cout << '\n';
		}
	}
	else if (N % 2 == 0) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++)
				cout << 'O';
			cout << '\n';
		}
	}
	else {
		N % 4 == 3 ? N = 3 : N = 5;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++)
				cout << board[N][i][j];
			cout << '\n';
		}
	}
	return 0;
}