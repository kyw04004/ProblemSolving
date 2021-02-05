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
int n, k, board[105][105], l, chk[105][105];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
map<int, pair<int,char>>m;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		m[x] = { 1,c };
	}
	int x = 1, y = 1, cnt = 1, slen = 1, d = 0;
	while (1) {
		if (x < 1 || x > n || y < 1 || y > n) break;
		if (chk[x][y] && (cnt - slen) >= 1 && (cnt - slen) <= chk[x][y]) break;
		chk[x][y] = cnt;
		if (m[cnt-1].first == 1) {
			if (m[cnt-1].second == 'L') d = (d - 1 + 4) % 4;
			else d = (d + 1) % 4;
		}
		x = x + dx[d];
		y = y + dy[d];
		if (board[x][y] == 1) {
			board[x][y] = 0;
			slen++;
		}
		cnt++;
	}
	cout << cnt-1;
	return 0;
}