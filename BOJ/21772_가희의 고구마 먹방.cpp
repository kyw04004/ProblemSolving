#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int R, C, T, ans, chk[101][101][11], sx, sy;
char board[101][101];
int dx[5] = { 0,0,-1,1,0 };
int dy[5] = { 1,-1,0,0,0 };
void dfs(int x, int y, int time, int cnt) {
	ans = max(ans, cnt);
	chk[x][y][time] = 1;
	if (time == T) return;
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
		if (board[nx][ny] == '#' || chk[nx][ny][time]) continue;
		if (board[nx][ny] == 'S') {
			board[nx][ny] = '.';
			dfs(nx, ny, time + 1, cnt + 1);
			board[nx][ny] = 'S';
		}
		else {
			dfs(nx, ny, time + 1, cnt);
		}
	}
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'G') sx = i, sy = j;
		}
	dfs(sx, sy, 0, 0);
	cout << ans;
	return 0;
}