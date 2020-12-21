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
vector<vector<int>> v(40001);
int depth[40001];
int par[40001][20];
int dist[40001];
int sum, p, a=1;
void dfs(int now, int level)
{
	depth[now] = level;
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i];
		if (depth[next]) continue;
		dist[next] = dist[now] + 1;
		dfs(next, level + 1);
		par[next][0] = now;
	}
}
int LCA(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);
	int dif = depth[a] - depth[b];
	for (int i = 0; i <= 16; i++)
		if (dif & (1 << i))
			a = par[a][i];
	if (a != b)
	{
		for (int i = 16; i >= 0; i--)
			if (par[a][i] && par[a][i] != par[b][i])
			{
				a = par[a][i];
				b = par[b][i];
			}
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
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 1);
	for (int i = 1; i <= 16; i++)
		for (int j = 1; j <= n; j++)
			par[j][i] = par[par[j][i - 1]][i - 1];
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		sum += dist[a];
		int b = a;
		scanf("%d", &a);
		sum += dist[a];
		sum -= 2 * dist[LCA(a, b)];
	}
	printf("%d\n", sum);
	return 0;
}