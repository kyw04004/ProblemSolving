#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, arr[1001],dp[1001];
int go(int st)
{
	int& ret = dp[st];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = st + 1; i <= n; i++)
		if (arr[st] < arr[i])
			ret = max(ret,go(i)+1);
	return ret;
}
int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) cin >> arr[i];
	cout<<go(0);
	return 0;
}