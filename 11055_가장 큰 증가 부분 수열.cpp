#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, dp[1001], arr[1001];
int go(int idx, int now)
{
	if (idx > n) return 0;
	int &ret = dp[idx];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = idx+1; i <= n; i++)
		if (arr[i] > arr[idx])
			ret = max(ret, go(i,arr[i])+arr[i]);
	return ret;
}
int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	printf("%d\n",go(0,0));
	return 0;
}