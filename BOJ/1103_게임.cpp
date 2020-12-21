#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int ans, n, m, arr[55][55], dp[55][55], Max, chk[55][55];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int go(int x, int y)
{
	if (x > n || y > m || x < 1 || y < 1 || arr[x][y] == 10) return 0;
	if (chk[x][y] == 1) return 1e9;
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	chk[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i] * arr[x][y];
		int ny = y + dy[i] * arr[x][y];
		ret = max(ret, go(nx, ny) + 1);
	}
	chk[x][y] = 0;
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			char c;
			scanf(" %c", &c);
			if (c == 'H') arr[i][j] = 10;
			else arr[i][j] = c - '0';
		}
	ans = go(1, 1);
	if (ans >=1e9) printf("-1");
	else printf("%d", ans);
	return 0;
}