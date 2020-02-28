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
int n, m, Min = 1e9;
int arr[102], dp[101][11][101];
int go(int now, int cnt, int pre, int sum)
{
	if (now == n+1)
		return 0;
	int &ret = dp[now][cnt][pre];
	if (ret != -1)
		return ret;
	ret = go(now + 1, cnt, pre, sum + arr[now]);
	if (cnt > 0)
		ret = min(ret,go(now + 1, cnt - 1, now, 0));
	return ret += arr[now] * sum;
}
void trace(int now, int cnt, int pre)
{
	for (int i = 1; i <= n - 1; i++)
	{
		if (cnt == 0)
			break;
		int a = dp[i + 1][cnt][pre], b = dp[i + 1][cnt - 1][i];
		if (a >= b)
		{
			pre = i;
			printf("%d ", i);
			cnt--;
		}
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	printf("%d\n", go(1, m, 0, 0));
	trace(1, m, 0);
	return 0;
}
