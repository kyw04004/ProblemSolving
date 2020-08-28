#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, m, arr[505][505],dp[505][505];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int go(int x, int y) {
	if (x == n && y == m) return 1;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 || ny <1 || nx>n || ny > m) continue;
		if(arr[x][y] > arr[nx][ny])
			ret += go(nx, ny);
	}
	return ret;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	memset(dp, -1, sizeof(dp));
	cout << go(1, 1);
	return 0;
}