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
int n, m, Map[55][55],x,y,d,cnt,chk[55][55],End;
int dx[4] = {0, -1, 0, 1 };
int dy[4] = {-1, 0, 1, 0 };
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	cin >> x >> y >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> Map[i][j];
	while (1) {
		if (End) break;
		if(!chk[x][y]) cnt++;
		chk[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nd = (d - i + 4) % 4;
			int nx = x + dx[nd];
			int ny = y + dy[nd];
			if (chk[nx][ny] || Map[nx][ny] == 1) {
				if (i == 3) {
					nd = (d + 1 + 4) % 4;
					nx = x - dx[nd];
					ny = y - dy[nd];
					if (Map[nx][ny] == 1) End = 1;
					else x = nx, y = ny;
				}
			}
			else {
				nd = (nd - 1 + 4) % 4;
				x = nx, y = ny, d = nd;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}