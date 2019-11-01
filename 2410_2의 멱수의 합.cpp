#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
long long dp[1000001];
long long dol[22];
long long sum = 1;
int main()
{
	for (int i = 1; i <= 21; i++)
	{
		dol[i] = sum;
		sum *= 2;
	}
	for (int i = 0; i <= 1000000; i++)
		dp[i] = 1;
	for (int i = 2; i <= 21; i++)
	{
		for (int j = 1; j <= 1000000; j++)
		{
			if (j - dol[i] >= 0)
				dp[j] = (dp[j - dol[i]] + dp[j]) % 1000000000;
		}
	}
	int n;
	cin >> n;
	printf("%lld", dp[n] % 1000000000);
	return 0;
}