#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int N, M, F, board[21][21];
int dx[4] = { 0,0,-1,1 };
int dy[4] = {1, -1, 0, 0};
pair<int,int> now;
struct passenger{
	int sx;
	int sy;
	int ex;
	int ey;
	int d;
};
vector<passenger> v;
bool compare(passenger a, passenger b) {
	if (a.sx != b.sx) return a.sx < b.sx;
	else return a.sy < b.sy;
}
int bfs(int sx, int sy, int ex, int ey) {
	int chk[22][22] = {};
	queue<pair<pair<int, int>, int>> q;
	chk[sx][sy] = 1;
	q.push({ { sx,sy },0 });
	while(!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		if (x == ex && y == ey) return d;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (board[nx][ny] || chk[nx][ny] || nx < 1 || ny > N || nx > N || ny < 1) continue;
			chk[nx][ny] = 1;
			q.push({ {nx,ny}, d + 1 });
		}
	}
	return -1;
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> F;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	cin >> now.first >> now.second;
	for (int i = 0; i < M; i++) {
		passenger p;
		cin >> p.sx >> p.sy >> p.ex >> p.ey;
		p.d = bfs(p.sx, p.sy, p.ex, p.ey);
		if (p.d == -1) {
			cout << -1;
			return 0;
		}
		v.push_back(p);
	}
	sort(v.begin(), v.end(), compare);
	int go[401] = {};
	int cnt = 0;
	while (1) {
		int minD = 1e9;
		int minI = -1;
		for (int i = 0; i < v.size(); i++) {
			if (go[i]) continue;
			int d = bfs(now.first,now.second,v[i].sx,v[i].sy);
			if (d == -1) continue;
			if (d < minD) {
				minD = d;
				minI = i;
			}
		}
		if (minI == -1) break;
		if (F >= (minD + v[minI].d)) {
			go[minI] = 1;
			cnt++;
			F -= minD;
			F += v[minI].d;
			now = { v[minI].ex, v[minI].ey };
		}
		else break;
	}
	if (cnt != M) cout << -1;
	else cout << F;
	return 0;
}