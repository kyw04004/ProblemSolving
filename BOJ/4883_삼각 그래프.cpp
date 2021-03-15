#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int t, n, arr[100005][5], dp[100005][5];
int go(int x, int y) {
	if (x == n && y == 2) return 0;
	int &ret = dp[x][y];
	if (ret != -1e9) return ret;
	ret = 1e9;
	if (y == 1) {
		if (x == n) ret = min(ret, go(x, y + 1) + arr[x][y + 1]);
		else {
			ret = min(ret, go(x + 1, y) + arr[x + 1][y]);
			ret = min(ret, go(x + 1, y + 1) + arr[x + 1][y + 1]);
			ret = min(ret, go(x, y + 1) + arr[x][y + 1]);
		}
	}
	if (y == 2) {
		if (x == n - 1) {
			ret = min(ret, go(x + 1, y) + arr[x + 1][y]);
			ret = min(ret, go(x, y + 1) + arr[x][y + 1]);
			ret = min(ret, go(x + 1, y - 1) + arr[x + 1][y - 1]);
		}
		else {
			ret = min(ret, go(x + 1, y) + arr[x + 1][y]);
			ret = min(ret, go(x + 1, y + 1) + arr[x + 1][y + 1]);
			ret = min(ret, go(x, y + 1) + arr[x][y + 1]);
			ret = min(ret, go(x + 1, y - 1) + arr[x + 1][y - 1]);
		}
	}
	if (y == 3) {
		if (x == n - 1) ret = min(ret, go(x + 1, y - 1) + arr[x + 1][y - 1]);
		else {
			ret = min(ret, go(x + 1, y) + arr[x + 1][y]);
			ret = min(ret, go(x + 1, y - 1) + arr[x + 1][y - 1]);
		}
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		t++;
		for (int i = 0; i <= 100004; i++)
			for (int j = 0; j <= 4; j++)
				dp[i][j] = -1e9;
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> arr[i][j];
		int com = go(1, 2) + arr[1][2];
		cout << t << ". " << com << "\n";
	}
	return 0;
}