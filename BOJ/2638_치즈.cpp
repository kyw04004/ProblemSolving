#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
#include<map>
using namespace std;
typedef long long ll;
int n, m, arr[105][105], time, chk[105][105];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
queue<pair<int,int>> q;
void bfs() {
	while (1) {
		bool end = true;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (arr[i][j] != 0) end = false;
		if (end == true) break;
		else time++;
		memset(chk, 0, sizeof(chk));
		chk[1][1] = 1;
		q.push({ 1,1 });
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (chk[nx][ny]) continue;
				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
				if (arr[nx][ny] == 0) {
					chk[nx][ny] = 1;
					q.push({ nx,ny });
				}
				else arr[nx][ny]++;
			}
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] >= 3) arr[i][j] = 0;
				if (arr[i][j] == 2) arr[i][j] = 1;
			}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	bfs();
	cout << time;
	return 0;
}