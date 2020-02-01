#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
long long arr[101],n;
long long dp[102][22];
int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &arr[i]);
	dp[1][arr[1]] = 1;
	for(int i=2;i<n;i++)
		for (int j = 0; j <= 20; j++)
		{
			if (0 <= j + arr[i] && j + arr[i] <= 20)
				dp[i][j+arr[i]] += dp[i - 1][j];
			if (0 <= j - arr[i] && j - arr[i] <= 20)
				dp[i][j-arr[i]] += dp[i - 1][j];
		}
	printf("%lld", dp[n-1][arr[n]]);
	return 0;
}