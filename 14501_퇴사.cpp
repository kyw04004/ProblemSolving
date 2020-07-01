#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, dp[16];
pair<int, int> arr[16];
int go(int idx)
{
	if (idx > n) return 0;
	int &ret = dp[idx];
	if (ret != -1) return ret;
	ret = 0;
	if (idx + 1 <= n)
		ret = max(ret, go(idx + 1));
	if(idx+arr[idx].first<=n+1)
		ret = max(ret, go(idx + arr[idx].first) + arr[idx].second);
	return ret;
}
int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> arr[i].first >> arr[i].second;
	printf("%d\n",go(0));
	return 0;
}