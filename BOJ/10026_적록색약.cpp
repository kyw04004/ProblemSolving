#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n,cnt1,cnt2,chk[105][105];
char Map[105][105];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue <pair<int, int>> q;
void bfs(int x, int y) {
	chk[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>n||chk[nx][ny] || Map[x][y] != Map[nx][ny])
				continue;
			chk[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> Map[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!chk[i][j]) cnt1++, bfs(i, j);
	memset(chk, 0, sizeof(chk));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (Map[i][j] == 'R') Map[i][j] = 'G';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!chk[i][j]) cnt2++, bfs(i, j);
	printf("%d %d", cnt1, cnt2);
	return 0;
}