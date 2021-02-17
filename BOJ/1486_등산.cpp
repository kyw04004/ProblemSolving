#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int n, m, t, d, Map[26][26], ans;
int up[26][26], down[26][26];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void dfs1(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (abs(Map[nx][ny] - Map[x][y] > t)) continue;
		if (Map[x][y] >= Map[nx][ny]) {
			if (up[nx][ny] > up[x][y] + 1) {
				up[nx][ny] = up[x][y] + 1;
				dfs1(nx, ny);
			}
		}
		else {
			int dif = Map[nx][ny] - Map[x][y];
			if (up[nx][ny] > up[x][y] + dif * dif) {
				up[nx][ny] = up[x][y] + dif * dif;
				dfs1(nx, ny);
			}
		}
	}
}
void dfs2(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (abs(Map[nx][ny] - Map[x][y] > t)) continue;
		if (Map[x][y] <= Map[nx][ny]) {
			if (down[nx][ny] > down[x][y] + 1) {
				down[nx][ny] = down[x][y] + 1;
				dfs2(nx, ny);
			}
		}
		else {
			int dif = Map[nx][ny] - Map[x][y];
			if (down[nx][ny] > down[x][y] + dif * dif) {
				down[nx][ny] = down[x][y] + dif * dif;
				dfs2(nx, ny);
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> t >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			up[i][j] = 1e9;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			down[i][j] = 1e9;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char a; cin >> a;
			if (a >= 'A' && a<= 'Z') a -= 'A';
			else a -= 'a', a += 26;
			Map[i][j] = a;
		}
	up[0][0] = 0;
	dfs1(0, 0);
	down[0][0] = 0;
	dfs2(0, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (up[i][j] + down[i][j] <= d)
				ans = max(ans, Map[i][j]);
	cout << ans;
	return 0;
}