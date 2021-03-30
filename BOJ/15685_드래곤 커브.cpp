#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
int N, dot[105][105], cnt;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int comx, comy, comd;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		comx = x, comy = y, comd = d;
		dot[x][y] = 1;
		stack<int> total;
		stack<int> level;
		comx += dx[comd];
		comy += dy[comd];
		dot[comx][comy] = 1;
		level.push(comd);
		total.push(comd);
		for (int j = 1; j <= g; j++) {
			level = total;
			while (!level.empty()) {
				int nd = level.top();
				level.pop();
				nd = (nd + 1) % 4;
				total.push(nd);
				comx += dx[nd];
				comy += dy[nd];
				dot[comx][comy] = 1;
			}
		}
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (dot[i][j] * dot[i + 1][j + 1] * dot[i + 1][j] * dot[i][j + 1]) cnt++;
	cout << cnt;
	return 0;
}