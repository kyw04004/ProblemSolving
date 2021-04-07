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
typedef pair<pair<int, int>, int> p;
vector<p> command;
vector<vector<p>> seq;
vector<p> comv;
int n, m, k, arr[55][55], chk[10], com[55][55], ans=1e9;
void go() {
	if (comv.size() == k) {
		seq.push_back(comv);
		return;
	}
	for (int i = 0; i < command.size(); i++) {
		if (chk[i] == 0) {
			chk[i] = 1;
			comv.push_back(command[i]);
			go();
			comv.pop_back();
			chk[i] = 0;
		}
	}
}
void rotation(int sx, int sy, int ex, int ey) {
	while (ex - sx > 0 && ey - sy > 0) {
		int temp = com[sx][ey];
		int temp2 = com[ex][ey];
		int temp3 = com[ex][sy];
		for (int i = ey; i > sy; i--) // 위쪽
			com[sx][i] = com[sx][i-1];
		for (int i = ex; i > sx; i--) { // 오른쪽
			if (i == sx + 1) {
				com[i][ey] = temp;
				continue;
			}
			com[i][ey] = com[i - 1][ey];
		}
		for (int i = sy; i < ey; i++) { // 아래쪽
			if (i == ey - 1) {
				com[ex][i] = temp2;
				continue;
			}
			com[ex][i] = com[ex][i + 1];
		}
		for (int i = sx; i < ex; i++) { // 왼쪽
			if (i == ex - 1) {
				com[i][sy] = temp3;
				continue;
			}
			com[i][sy] = com[i + 1][sy];
		}
		sx++, sy++, ex--, ey--;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		command.push_back({ {r,c},s });
	}
	go();
	for (int i = 0; i < seq.size(); i++) {
		for (int a = 1; a <= n; a++)
			for (int b = 1; b <= m; b++)
				com[a][b] = arr[a][b];
			
		for (int j = 0; j < seq[i].size(); j++) {
			int r = seq[i][j].first.first;
			int c = seq[i][j].first.second;
			int s = seq[i][j].second;
			rotation(r-s,c-s,r+s,c+s);
		}
		int Min = 1e9;
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++)
				sum += com[i][j];
			Min = min(Min, sum);
		}
		ans = min(ans, Min);
	}
	cout << ans;
	return 0;
}