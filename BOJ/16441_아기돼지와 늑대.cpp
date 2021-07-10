#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int N, M, chk[105][105][5];
char board[105][105];
queue<pair<pair<int, int>, int>> q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();

		if (board[x][y] == '+') {
			while (board[x][y] == '+') {
				chk[x][y][d] = 1;
				x += dx[d];
				y += dy[d];
			}
			if (board[x][y] == '.') chk[x][y][d] = 1;
			if (board[x][y] == '#') x -= dx[d], y -= dy[d];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > N || ny < 1 || ny > M ||
				board[nx][ny] == '#' || chk[nx][ny][i]) continue;
			chk[nx][ny][i] = 1;
			q.push({ { nx, ny }, i });
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'W') {
				chk[i][j][4] = 1;
				q.push({ { i,j }, 4 });
			}
		}

	bfs();

	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= M; y++) {
			if (board[x][y] == '#' || board[x][y] == '+') continue;
			if (chk[x][y][0] + chk[x][y][1] +
				chk[x][y][2] + chk[x][y][3] + chk[x][y][4] == 0) board[x][y] = 'P';
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cout << board[i][j];
		cout << '\n';
	}
	return 0;
}