#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
int n, Max;
int dp[501][501];
int arr[501][501];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
void dfs(int x, int y)
{
	int value=0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && arr[nx][ny] > arr[x][y])
		{
			if (dp[nx][ny] == 0)
				dfs(nx, ny);
			if (value < dp[nx][ny])
				value = dp[nx][ny];
		}
	}
	dp[x][y] = value + 1;
	Max = max(Max, dp[x][y]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (dp[i][j] == 0)
				dfs(i, j);
	printf("%d", Max);
	return 0;
}