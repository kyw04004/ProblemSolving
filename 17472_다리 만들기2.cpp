#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int n, m, Map[11][11], chk[11][11], cnt, parent[11], sum, ok = 1,chk2[10][11][11];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> q;
priority_queue<pair<pair<int, int>, pair<int, int>>, 
	vector<pair<pair<int, int>, pair<int, int>>>, 
	greater<pair<pair<int, int>, pair<int, int>>>> q2;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
void bfs1(int x, int y) {
	q.push({ x,y });
	chk[x][y] = 1;
	Map[x][y] = cnt;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk[nx][ny] || nx<1 || nx > n || ny < 1 || ny > m) continue;
			if (Map[nx][ny] == 1) {
				chk[nx][ny] = 1;
				Map[nx][ny] = cnt;
				q.push({ nx,ny });
			}
		}
	}
}
void bfs2(int x, int y, int val, int me) {
	for (int i = 0; i < 4; i++) q2.push({ {val,i},{x,y} });
	chk2[me][x][y] = 1;
	while (!q2.empty()) {
		int x = q2.top().second.first;
		int y = q2.top().second.second;
		int val = q2.top().first.first;
		int dir = q2.top().first.second;
		q2.pop();
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (chk2[me][nx][ny] || nx<1 || nx > n || ny < 1 || ny > m) continue;
		chk2[me][nx][ny] = 1;
		if (Map[nx][ny] == 0) q2.push({ {val + 1,dir},{ nx,ny }, });
		else if (Map[nx][ny] == me) 
			for (int i = 0; i < 4; i++) q2.push({ {val,i},{ nx,ny }, });
		else {
			if (val == 1) continue;
			pq.push({ val,{me, Map[nx][ny]} });
		}

	}
}
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}
bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> Map[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!chk[i][j] && Map[i][j] == 1)
				cnt++, bfs1(i, j);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			if (!chk2[Map[i][j]][i][j] && Map[i][j])
				bfs2(i, j, 0, Map[i][j]);
	for (int i = 1; i <= cnt; i++) parent[i] = i;
	while (!pq.empty()) {
		if (!isUnion(pq.top().second.first, pq.top().second.second)) {
			sum += pq.top().first;
			merge(pq.top().second.first, pq.top().second.second);
		}
		pq.pop();
	}
	for (int i = 2; i <= cnt; i++)
		if (!isUnion(i - 1, i)) ok = 0;
	if (ok) cout << sum;
	else cout << "-1";
	return 0;
}