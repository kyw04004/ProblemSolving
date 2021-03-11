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
int n, m, lab[55][55], ans = 1e9, dist[55][55], Max;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>> disabled;
vector<pair<int, int>> permutation;
vector<vector<pair<int, int>>> abled;
queue<pair<int, int>> q;
void make_permutation(int index) {
	if (permutation.size() == m) {
		abled.push_back(permutation);
		return;
	}
	for (int i = index; i < disabled.size(); i++) {
		permutation.push_back(disabled[i]);
		make_permutation(i + 1);
		permutation.pop_back();
	}
}
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
			if (lab[nx][ny] == 1) continue;
			if (dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[x][y] + 1;
			if (lab[nx][ny] == 0) Max = dist[nx][ny];
			q.push({ nx,ny });
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) disabled.push_back({ i,j });
		}
	make_permutation(0);
	for (int i = 0; i < abled.size(); i++) {
		memset(dist, -1, sizeof(dist));
		for (int j = 0; j < abled[i].size(); j++) {
			int x = abled[i][j].first;
			int y = abled[i][j].second;
			lab[x][y] = 4;
			dist[x][y] = 0;
			q.push({x,y });
		}
		Max = 0;
		bfs();
		for (int a = 1; a <= n; a++)
			for (int b = 1; b <= n; b++) {
				if (lab[a][b] != 1 && dist[a][b] == -1) {
					Max = 1e9;
					a = n + 1, b = n + 1;
				}
			}
		ans = min(ans, Max);
		for (int j = 0; j < abled[i].size(); j++) {
			int x = abled[i][j].first;
			int y = abled[i][j].second;
			lab[x][y] = 2;
		}
	}
	if (ans == 1e9) ans = -1;
	cout << ans;
	return 0;
}