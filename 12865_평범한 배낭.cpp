#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, k, w[101],v[101], dp[105][100005];
int go(int now,int cap)
{
	if (now == n+1) return 0;
	int& ret = dp[now][cap];
	if (ret != -1) return ret;
	if (w[now] <= cap) ret = go(now + 1, cap - w[now]) + v[now];
	ret = max(ret, go(now + 1, cap));
	return ret;
}
int main()
{
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> w[i]>>v[i];
	cout << go(1,k);
	return 0;
}