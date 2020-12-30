#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int n, m, s = 1;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
char arr[22][22];
queue<pair<pair<int, int>, pair<int, int>>> q;
int bfs() {
	while (!q.empty()) {
		int x1 = q.front().first.first;
		int y1 = q.front().first.second;
		int cnt1 = q.front().second.first;
		int s1 = q.front().second.second;
		q.pop();
		int x2 = q.front().first.first;
		int y2 = q.front().first.second;
		int cnt2 = q.front().second.first;
		int s2 = q.front().second.second;
		q.pop();
		if ((x1 < 1 || x1> n || y1<1 || y1>m) && (x2 < 1 || x2> n || y2<1 || y2>m)) continue;
		if ((x1 < 1 || x1> n || y1<1 || y1>m) && !(x2 < 1 || x2> n || y2<1 || y2>m)) return cnt1;
		if (!(x1 < 1 || x1> n || y1<1 || y1>m) && (x2 < 1 || x2> n || y2<1 || y2>m)) return cnt2;
		if (cnt1 > 10 || cnt2 > 10) return -1;
		for (int i = 0; i < 4; i++) {
			int nx1 = x1 + dx[i];
			int ny1 = y1 + dy[i];
			int nx2 = x2 + dx[i];
			int ny2 = y2 + dy[i];
			if (arr[nx1][ny1] == '#') q.push({ {x1,y1},{cnt1 + 1,s} });
			else q.push({ {nx1,ny1},{cnt1 + 1,s} });
			if (arr[nx2][ny2] == '#') q.push({ {x2,y2},{cnt2 + 1,s} });
			else q.push({ {nx2,ny2},{cnt2 + 1,s} });
		}
	}
	return -1;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'o') q.push({ {i,j},{0,s++} });
		}
	cout << bfs();
	return 0;
}