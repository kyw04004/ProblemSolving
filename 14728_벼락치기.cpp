#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, t, time[102], score[102], dp[101][10001];
int go(int index, int totaltime)
{
	if (index == n) return 0;
	int& ret = dp[index][totaltime];
	if (ret != -1) return ret;
	ret = 0;
	if(totaltime + time[index+1] <= t)
		ret = go(index + 1, totaltime + time[index + 1])+score[index+1];
	ret = max(ret, go(index + 1, totaltime));
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> t;
	for (int i = 1; i <= n; i++) cin >> time[i] >> score[i];
	printf("%d\n",go(0,0));
	return 0;
}