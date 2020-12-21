#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m, k,arr[1001][1001],dp[1001][1001];
void dfs(int x,int y)
{
	if (x > n || y > m) 
	{
		printf("%d %d", x, y);
		return;
	}
	if (arr[x][y] == 1) dfs(x,y+1);
	else dfs(x+1,y);
}
int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(" %d", &arr[i][j]);
	dp[1][1] = k-1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int val = dp[i][j];
			if (val % 2 == 1)
			{
				if (arr[i][j] == 1)
				{
					dp[i][j + 1] += val / 2 + 1;
					dp[i + 1][j] += val / 2;
				}
				else
				{
					dp[i][j + 1] += val / 2;
					dp[i + 1][j] += val / 2 + 1;
				}
			}
			else
			{
				dp[i][j + 1] += val / 2;
				dp[i + 1][j] += val / 2;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (dp[i][j] % 2 == 1)
				arr[i][j] == 1 ? arr[i][j] = 0 : arr[i][j] = 1;
	dfs(1, 1);
	return 0;
}