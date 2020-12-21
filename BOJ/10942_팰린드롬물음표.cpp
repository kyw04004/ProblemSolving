#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,m,arr[2005],dp[2005][2005];
int go(int st, int en)
{
	if (st>=en) return 1;
	int& ret = dp[st][en];
	if (ret != -1) return ret;
	ret = 0;
	if (arr[st] == arr[en]) ret = go(st + 1, en - 1);
	else ret = 0;
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", go(a,b));
	}
	return 0;
}