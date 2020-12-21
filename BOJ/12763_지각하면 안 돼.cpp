#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<pair<int,pair<int,int>>>> v(101);
int dp[101][10001];
int n, finish, time, money,ans;
int dfs(int now,int t,int sum) {
	int& ret = dp[now][t];
	if (now == finish) return 0;
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i].first;
		int nextcost = v[now][i].second.second;
		int nexttime = v[now][i].second.first;
		if (t + nexttime <= time && sum + nextcost <= money)
			ret = min(ret, dfs(next,t+nexttime,sum+nextcost)+v[now][i].second.second);
	}
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> finish>>time >> money >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[a].push_back({ b,{c,d} });
		v[b].push_back({ a,{c,d} });
	}
	ans = dfs(1, 0, 0);
	if (ans == 1e9) printf("-1");
	else printf("%d",ans);
	return 0;
}