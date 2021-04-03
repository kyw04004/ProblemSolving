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
typedef pair<int, int> p;
typedef pair<p, int> pp;
int N, L, R, population[51][51], chk[51][51], cnt, sum, num, share, ans;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue<pp> q;
void bfs(int x, int y, int val) {
	sum = 0;
	cnt = 0;
	chk[x][y] = num;
	q.push({ {x,y}, val });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int val = q.front().second;
		cnt++;
		sum += val;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nd = abs(population[x][y] - population[nx][ny]);
			if (chk[nx][ny] || nx<1 || nx>N || ny<1 || ny>N) continue;
			if (L <= nd && nd <= R) {
				chk[nx][ny] = num;
				q.push({ {nx,ny}, population[nx][ny] });
			}
		}
	}
	if (cnt > 1) {
		share = sum / cnt;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (chk[i][j] == num)
					population[i][j] = share;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> population[i][j];
	while (1) {
		ans++;
		share = 0;
		num = 0;
		memset(chk, 0, sizeof(chk));
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (chk[i][j] == 0) {
					num++;
					bfs(i, j, population[i][j]);
				}
		if (share == 0) {
			ans--;
			break;
		}
	}
	cout << ans;
	return 0;
}