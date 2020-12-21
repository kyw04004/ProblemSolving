#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int dp[10001];
int dol[101];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &dol[i]);
	for (int i = 1; i <= n; i++)
		sort(dol + 1, dol + n + 1);
	for (int i = 1; i <= k; i++)
		dp[i] = 1e9;
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= k; i++)
			if(i>=dol[j])
				dp[i] = min(dp[i - dol[j]] + 1, dp[i]);
	if (dp[k] == 1e9)
		printf("-1");
	else
		printf("%d", dp[k]);
	return 0;
}