#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int arr[1001][4];
int dp[1001][4];
int n, Min = 1e6;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			scanf("%d", &arr[i][j]);
	for (int k = 1; k <= 3; k++)
	{
		for (int i = 1; i <= 3; i++)
		{
			if (k == i)
				dp[1][i] = arr[1][i];
			else
				dp[1][i] = 1001;
		}

		for (int i = 2; i <= n; i++)
		{
			dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + arr[i][2];
			dp[i][3] = min(dp[i - 1][2], dp[i - 1][1]) + arr[i][3];
		}

		for (int i = 1; i <= 3; i++)
		{
			if (i == k)
				continue;
			Min = min(Min, dp[n][i]);
		}
	}
	printf("%d\n", Min);
	return 0;
}