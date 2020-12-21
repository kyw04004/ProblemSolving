#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int t, dp[2002][2002];
int go(int now, int sum, int end)
{
	if (sum == end) return 1;
	else if (now == end || sum > end) return 0;
	int& ret = dp[now][sum];
	if (ret != -1) return ret;
	ret = 0;
	ret = go(now + 1, sum, end) + go(now + 1, sum + now + 1, end);
	return ret % 100999;
}
int main()
{
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		memset(dp, -1, sizeof(dp));
		printf("%d\n", go(0, 0,n));
	}
	return 0;
}