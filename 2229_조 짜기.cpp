#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, dp[1001], arr[1001];
int go(int idx)
{
	if (idx > n) return 0;
	int &ret = dp[idx];
	if (ret != -1) return ret;
	ret = 0;
	int Min = 10001, Max = -1;
	for (int i = idx; i <= n; i++)
	{
		Min = min(Min, arr[i]);
		Max = max(Max, arr[i]);
		ret = max(ret, go(i + 1) + Max - Min);
	}
	return ret;
}
int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	printf("%d\n",go(1));
	return 0;
}