#include<stdio.h>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef pair<int, int> P;
int n, m,arr[11],dp[361],ans;
int go(int angle)
{
	if (angle > 360) return 0;
	int &ret = dp[angle];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 1; i <= n; i++)
	{
		go((angle + arr[i])%360);
		if(angle-arr[i]>=0)
			ret=go((angle - arr[i]) % 360);
		else
			ret=go(abs(angle - arr[i]) % 360);
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	go(0);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &ans);
		if (dp[ans] == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}