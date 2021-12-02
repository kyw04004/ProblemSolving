#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int board[50][5], r1,c1, r2, c2;
int dx[4] = { 1,0,-1,0 }; //DRUL
int dy[4] = { 0,1,0,-1 };
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> r1 >> c1 >> r2 >> c2;
	r1 += 5000, r2 += 5000, c1 += 5000, c2 += 5000;
	int now = 1, x = 5000, y = 5000, len = 1, d = 0;
	bool done = false;
	int Max = 0;
	if (r1 <= x && x <= r2 && c1 <= y && y <= c2)
		board[x - r1][y - c1] = now, Max = max(Max, now);
	while (!done) {
		for (int i = 1; i <= (2 * len); i++) {
			if (i == 1 || i == len + 1) d += 1, d %= 4;
			now += 1;
			x += dx[d];
			y += dy[d];
			if (0 > x || x > 10000 || 0 > y || y > 10000) {
				done = true;
				break;
			}
			if (r1 <= x && x <= r2 && c1 <= y && y <= c2)
				board[x - r1][y - c1] = now, Max = max(Max, now);
		}
		len++;
	}
	int maxLen = to_string(Max).size();
	for (int i = 0; i <= r2 -r1; i++) {
		for (int j = 0; j <= c2 -c1; j++) {
			int numLen = to_string(board[i][j]).size();
			for(int k=0;k < (maxLen-numLen);k++)
				cout <<' ';
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}