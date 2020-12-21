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
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &dol[i]);
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (j >= dol[i])
				dp[j]+=dp[j-dol[i]];
		}
	}
	printf("%d", dp[k]);
	return 0;
}