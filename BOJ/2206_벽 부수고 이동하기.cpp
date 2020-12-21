#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n, m, chk[2][1005][1005];
char arr[1005][1005];
queue<pair<pair<int, int>, pair<int,int>>> q;
int bfs(int x, int y) {
	chk[0][x][y] = 1;
	q.push({ {x,y},{0,1} });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int key = q.front().second.first;
		int cnt = q.front().second.second;
		if (x == n && y == m) return cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk[key][nx][ny] || nx > n || nx<1 || ny>m || ny < 1) continue;
			if (arr[nx][ny] == '0') {
				chk[key][nx][ny] = 1;
				q.push({ {nx,ny},{key,cnt + 1} });
			}
			if ((arr[nx][ny] == '1') && !key) {
				chk[key][nx][ny] = 1;
				q.push({ {nx,ny},{key+1,cnt + 1} });
			}
		}
	}
	return -1;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	printf("%d", bfs(1,1));
	return 0;
}