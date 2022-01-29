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
typedef unsigned long long ll;
typedef pair<pair<int, int>, pair<int, int>> p;
int w, h, chk[5][105][105],sx,sy,ex,ey;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char board[101][101];
int bfs(int x, int y) {
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push({ {0,4}, {x,y} });
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cnt = pq.top().first.first;
		int d = pq.top().first.second;
		pq.pop();
		if(chk[d][x][y]) continue;
		chk[d][x][y] = 1;
		if (x == ex && y == ey) return cnt;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > h || ny < 1 || ny > w) continue;
			if (board[nx][ny] == '*') continue;
			if (d != 4 && i != d) pq.push({ {cnt + 1, i}, {nx,ny} });
			else  pq.push({ {cnt,i}, {nx,ny} });
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> w >> h;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'C') {
				if (sx == 0) sx = i, sy = j;
				else ex = i, ey = j;
			}
		}
	cout << bfs(sx, sy);
	return 0;
}