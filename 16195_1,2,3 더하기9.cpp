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
typedef long long ll;
ll t, n, m, dp[1005][1005];
int main()
{
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;
	for (int i = 4; i <= 1000; i++)
		for (int j = 1; j <= 1000; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % 1000000009;
	scanf("%lld", &t);
	while (t--)
	{
		ll sum = 0;
		scanf("%lld %lld", &n, &m);
		for (int i = 1; i <= m; i++)
			sum += (dp[n][i] % 1000000009);
		printf("%lld\n", sum % 1000000009);
	}
	return 0;
}

