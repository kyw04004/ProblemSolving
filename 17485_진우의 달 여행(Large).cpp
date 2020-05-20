#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,m,arr[1001][1001], dp[1001][1001][4], Min = 1e9;
int dx[3] = { 1,1,1 };
int dy[3] = { -1,0,1 };
int go(int x, int y,int past)
{
	if (x == n) return 0;
	int &ret = dp[x][y][past];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (i == past || nx<1 || nx > n || ny < 1 || ny > m) continue;
		ret = min(ret, go(nx, ny, i) + arr[nx][ny]);
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 1; i <= m; i++)
		Min = min(Min, arr[1][i] + go(1, i,-1));
	printf("%d\n", Min);
	return 0;
}