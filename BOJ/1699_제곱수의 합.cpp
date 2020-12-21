#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int dp[100001];
int dol[355];
int main()
{
	int k;
	scanf("%d",&k);
	for (int i = 1; i <= 350; i++)
		dol[i] = i * i;
	for (int i = 1; i <= k; i++)
		dp[i] = 1e9;
	for (int j = 1; j <= 350; j++)
		for (int i = 1; i <= k; i++)
			if (i >= dol[j])
				dp[i] = min(dp[i - dol[j]] + 1, dp[i]);
	printf("%d", dp[k]);
	return 0;
}