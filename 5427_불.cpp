#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
int t, n, m, fchk[1005][1005], schk[1005][1005], ans;
char arr[1005][1005];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int time[1005][1005];
int time2[1005][1005];
queue<pair<pair<int, int>, int>> fq, sq;
void fbfs() {
	while (!fq.empty()) {
		int x = fq.front().first.first;
		int y = fq.front().first.second;
		int t = fq.front().second;
		fq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx > n || nx<1 || ny>m || ny < 1 || fchk[nx][ny] || arr[nx][ny] == '#') continue;
			fchk[nx][ny] = 1;
			fq.push({ {nx,ny}, t + 1 });
			time[nx][ny] = t + 1;
		}
	}
}
int sbfs(int x, int y) {
	schk[x][y] = 1;
	sq.push({ {x,y},0 });
	while (!sq.empty()) {
		int x = sq.front().first.first;
		int y = sq.front().first.second;
		int t = sq.front().second;
		sq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m) return t + 1;
			if (schk[nx][ny] || arr[nx][ny] == '#' || arr[nx][ny]=='*') continue;
			if ((t + 1 < time[nx][ny]) || !time[nx][ny]) {
				schk[nx][ny] = 1;
				sq.push({ {nx,ny}, t + 1 });
				time2[nx][ny] = t + 1;
			}
		}
	}
	return 0;
}
int main() {
	cin >> t;
	while (t--) {
		ans = 0;
		while (!fq.empty()) fq.pop();
		while (!sq.empty()) sq.pop();
		memset(time, 0, sizeof(time));
		memset(fchk, 0, sizeof(fchk));
		memset(schk, 0, sizeof(schk));
		scanf("%d %d", &m, &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				scanf(" %c", &arr[i][j]);
				if (arr[i][j] == '*') {
					fchk[i][j] = 1;
					fq.push({ {i,j},0 });
				}
			}
		fbfs();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (arr[i][j] == '@') ans = sbfs(i, j);
		if (!ans) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);
	}
	return 0;
}