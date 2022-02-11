#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int> > p;
int R, C, sx, sy, ans;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
char board[1501][1501];
int chk[1501][1501];
int meltT[1501][1501];
int meetBfs() {
	priority_queue<p, vector<p>, greater<p> > pq;
	chk[sx][sy] = 1;
	pq.push({ 0, { sx,sy } });
	while (!pq.empty()) {
		int t = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
			if (chk[nx][ny]) continue;
			if (board[nx][ny] == 'L') return t;
			chk[nx][ny] = 1;
			pq.push({ max(t, meltT[nx][ny]),{ nx,ny } });
		}
	}
	return false;
}
void calcTime(int x, int y) {
	queue<pair<pair<int, int>, int> > q;
	meltT[x][y] = 0;
	q.push({ {x,y}, 0 });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();
		if (meltT[x][y] < t) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > R || ny < 1 || ny > C) continue;
			if (board[nx][ny] == 'X') {
				if (t + 1 < meltT[nx][ny]) {
					meltT[nx][ny] = t + 1;
					q.push({ {nx,ny},meltT[nx][ny] });
				}
			}
			else if (meltT[nx][ny] == 1e9) {
				meltT[nx][ny] = 0;
				q.push({ {nx,ny},0 });
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
			meltT[i][j] = 1e9;
			cin >> board[i][j];
			if (board[i][j] == 'L') sx = i, sy = j;
		}
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			if (board[i][j] != 'X' && meltT[i][j] == 1e9)
				calcTime(i, j);
	cout << meetBfs();
	return 0;
}