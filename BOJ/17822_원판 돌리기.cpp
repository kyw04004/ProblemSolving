#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int board[51][51], N, M, T;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void stand() {
	int sum = 0, cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j] != -1) cnt++, sum += board[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (board[i][j] != -1) {
				if (board[i][j] * cnt > sum) board[i][j] -= 1;
				else if (board[i][j] * cnt < sum) board[i][j] += 1;
			}
}
void calc() {
	bool can = false;
	int chk[51][51] = {};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int now = board[i][j];
			if (now == -1) continue;
			bool del = false;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = (j + dy[k] + M) % M;
				if (nx < 0 || nx > N - 1) continue;
				if (board[i][j] == board[nx][ny]) {
					chk[nx][ny] = 1;
					del = true;
				}
			}
			if (del) chk[i][j] = 1, can = true;
		}
	}
	if (can == true) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (chk[i][j]) board[i][j] = -1;
	}
	else stand();
}
void rotate(int x, int d, int k) {
	for (int i = x - 1; i < N; i += x) {
		if (d == 0) {
			for (int j = 0; j < k; j++) {
				int temp = board[i][M-1];
				for (int idx = M-1; idx > 0; idx--)
					board[i][idx] = board[i][idx - 1];
				board[i][0] = temp;
			}
		}
		if (d == 1) {
			for (int j = 0; j < k; j++) {
				int temp = board[i][0];
				for (int idx = 0; idx < M - 1; idx++)
					board[i][idx] = board[i][idx + 1];
				board[i][M-1] = temp;
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		rotate(x, d, k);
		calc();
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if(board[i][j] != -1)
				sum += board[i][j];
	cout << sum;
	return 0;
}