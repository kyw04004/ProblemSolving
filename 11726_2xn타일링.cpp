#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dp[1001];
int n;
int main()
{
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= 1000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2])%10007;
	printf("%d", dp[n]%10007);
	return 0;
}