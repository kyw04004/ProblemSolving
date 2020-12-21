#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string a, b;
int dp[1005][1005];
int go(int ai,int bi)
{
	if (ai < 0 || bi < 0) return abs(ai - bi);
	int& ret = dp[ai][bi];
	if (ret != -1) return ret;
	ret = 1e9;
	if (a[ai] == b[bi]) ret = min(ret,go(ai - 1, bi - 1));
	else ret = min(min(ret,go(ai - 1, bi-1)+1), min(go(ai,bi-1)+1,go(ai - 1, bi)+1));
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> a >> b;
	printf("%d",go(a.size() - 1, b.size() - 1));
	return 0;
}