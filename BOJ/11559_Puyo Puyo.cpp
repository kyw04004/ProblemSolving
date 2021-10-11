#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
char board[12][6];
int chk[20][12][6];
int ansCnt;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void down() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			if (board[i][j] == '.') {
				for (int k = i; k > 0; k--)
					board[k][j] = board[k - 1][j];
				board[0][j] = '.';
			}
}
void bfs(int step, int x, int y, char c) {
	queue<p> q, delQ;
	chk[step][x][y] = 1;
	q.push({ x,y });
	delQ.push({ x,y });
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx>11 || ny < 0 || ny>5) continue;
			if (!chk[step][nx][ny] && board[nx][ny] == c) {
				cnt++;
				chk[step][nx][ny] = 1;
				q.push({ nx,ny });
				delQ.push({ nx,ny });
			}
		}
	}
	if (cnt >= 4) {
		while (!delQ.empty()) {
			int x = delQ.front().first;
			int y = delQ.front().second;
			delQ.pop();
			board[x][y] = 'X';
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> board[i][j];

	for (int k = 0; k <= ansCnt; k++) {
		for (int i = 0; i < 12; i++) // check bomb!
			for (int j = 0; j < 6; j++) {
				if (board[i][j] == '.' || chk[k][i][j]) continue;
				bfs(k, i, j, board[i][j]);
			}
		bool bomb = false;
		for (int i = 0; i < 12; i++) // delete bomb!
			for (int j = 0; j < 6; j++)
				if (board[i][j] == 'X') {
					board[i][j] = '.';
					bomb = true;
				}
		if (bomb) {
			down();
			ansCnt++;
		}
	}
	cout << ansCnt << '\n';
	return 0;
}