#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
vector<vector<pair<int, int>>> v(100001);
int depth[100001];
int par[100001][21];
int Min[100001][21];
int Max[100001][21];
int Ma, Mi;
void dfs(int now, int level)
{
	depth[now] = level;
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i].first;
		int nextcost = v[now][i].second;
		if (depth[next]) continue;
		dfs(next, level + 1);
		par[next][0] = now;
		Min[next][0] = nextcost;
		Max[next][0] = nextcost;
	}
}
int LCA(int a, int b)
{
	Mi = 1e9, Ma = 0;
	if (depth[a] < depth[b]) swap(a, b);
	int dif = depth[a] - depth[b];
	for (int i = 0; i <= 20; i++)
		if (dif & (1 << i))
		{
			Ma = max(Ma, Max[a][i]);
			Mi = min(Mi, Min[a][i]);
			a = par[a][i];
		}
	if (a != b)
	{
		for (int i = 20; i >= 0; i--)
			if (par[a][i] && par[a][i] != par[b][i])
			{
				Ma = max(Ma, Max[a][i]);
				Mi = min(Mi, Min[a][i]);
				Ma = max(Ma, Max[b][i]);
				Mi = min(Mi, Min[b][i]);
				a = par[a][i];
				b = par[b][i];
			}
		Ma = max(Ma, Max[a][0]);
		Mi = min(Mi, Min[a][0]);
		Ma = max(Ma, Max[b][0]);
		Mi = min(Mi, Min[b][0]);
		a = par[a][0];
	}
	return a;
}
int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 0; i <= 100000; i++)
		for (int j = 0; j <= 20; j++)
			Min[i][j] = 1e9;
	dfs(1, 1);
	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= n; j++)
		{
			Min[j][i] = min(Min[j][i - 1], Min[par[j][i - 1]][i - 1]);
			Max[j][i] = max(Max[j][i - 1], Max[par[j][i - 1]][i - 1]);
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		LCA(a, b);
		printf("%d %d\n", Mi,Ma);
	}
	return 0;
}