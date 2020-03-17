#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
ll t, n, ans, dp[101][101][2], chk[101];
ll go(ll depth, ll now, ll size)
{
	if (depth == n)
		return 1;
	ll &ret = dp[depth][now][size];
	if (ret != -1) return ret;
	ret = 0;
	if (size == 0)
		for (int i = now + 1; i <= n; i++)
			if (chk[i] == 0)
				chk[i] = 1, ret += go(depth + 1, i, 1),ret %= 1000000, chk[i] = 0;
	if (size == 1)
		for (int i = now - 1; i >= 1; i--)
			if (chk[i] == 0)
				chk[i] = 1, ret += go(depth + 1, i, 0), ret %= 1000000, chk[i] = 0;
	return ret % 1000000;
}
int main()
{
	scanf("%lld", &n);
	memset(dp, -1, sizeof(dp));
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}
	for (ll i = 1; i <= n; i++)
	{
		chk[i] = 1;
		ans += go(1, i, 0);
		ans %= 1000000;
		ans += go(1, i, 1);
		ans %= 1000000;
		chk[i] = 0;
	}
	printf("%lld\n", ans % 1000000);
	return 0;
}