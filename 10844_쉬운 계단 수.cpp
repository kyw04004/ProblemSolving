#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
long long dp[101][11],n,sum;
int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= 100; i++)
		for (int j = 0; j <= 9; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
	for (int i = 0; i <= 9; i++)
		sum = (sum+dp[n][i])%1000000000;
	printf("%lld", sum);
	return 0;
}