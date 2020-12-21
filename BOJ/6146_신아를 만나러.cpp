#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int X, Y, N, chk[1001][1001];
char Map[1001][1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue < pair<pair<int, int>, int>> q;
int bfs(int x, int y) {
	chk[x][y] = 1;
	q.push({ {x,y},0 });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (x == X+500 && y == Y+500) return cnt;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk[nx][ny] || nx < 0 || nx >1000 || ny < 0 || ny>1000) continue;
			if (Map[nx][ny] == '.') {
				chk[nx][ny] = 1;
				q.push({ { nx,ny }, cnt + 1 });
			}
		}
	}
}
int main() {
	cin >> X >> Y >> N;
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			Map[i][j] = '.';
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		Map[a+500][b+500] = 'M';
	}
	printf("%d\n",bfs(500,500));
 	return 0;
}