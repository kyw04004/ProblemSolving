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
int w, h, si, sj;
int chk[22][22][1 << 11];
vector<vector<char>> room;
map<pair<int,int>, int> m;
struct element {
	int x;
	int y;
	int cnt;
	int key;
};
int bfs(int sx, int sy, int dcnt) {
	queue<element> q;
	q.push({ sx, sy, 0, 1 });
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int key = q.front().key;
		q.pop();
		if (key == (1 << dcnt + 1) - 1) return cnt;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (room[nx][ny] == 'x' || chk[nx][ny][key]) continue;
			if (room[nx][ny] == '*') {
				chk[nx][ny][key] = 1;
				q.push({ nx,ny,cnt + 1, key | (1 << m[{nx, ny}]) });
			}
			else {
				chk[nx][ny][key] = 1;
				q.push({ nx,ny,cnt + 1, key });
			}
		}
	}
	return -1;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		memset(chk, 0, sizeof(chk));
		int dirty = 0;
		m.clear();
		room.clear();
		room.resize(25);
		cin >> w >> h;
		if (w + h == 0) break;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				char c; cin >> c;
				room[i].push_back(c);
				if (c == 'o') si = i, sj = j;
				if (c == '*') dirty++, m[{i, j}] = dirty;
			}
		int ans = bfs(si, sj, dirty);
		cout << ans << '\n';
	}
	return 0;
}