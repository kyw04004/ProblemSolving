#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<vector<int>> v(100001);
int ind[100001];
int chk[100001];
int dp[100001];
int V, E, Max;
void dfs(int now)
{
	int conq = 0;
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i];
		if (ind[next] > ind[now])
		{
			if (dp[next] == 0)
				dfs(next);
			if (conq < dp[next])
				conq = dp[next];
		}
	}
	dp[now] = conq + 1;
}
int main()
{
	cin >> V >> E;
	for (int i = 1; i <= E; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		ind[a]++;
		ind[b]++;
	}
	for (int i = 0; i < V; i++)
		dfs(i);
	sort(dp, dp + V);
	printf("%d", dp[V - 1]);
	return 0;
}