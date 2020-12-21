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
typedef long long ll;
vector<vector<pair<int, long long>>> v(100001);
int depth[100001];
ll dist[100001];
int par[100001][20];
void dfs(int now, int level)
{
	depth[now] = level;
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i].first;
		ll nextcost = v[now][i].second;
		if (depth[next]) continue;
		dist[next] = dist[now] + nextcost;
		dfs(next, level + 1);
		par[next][0] = now;
	}
}
int LCA(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);
	int dif = depth[a] - depth[b];
	for (int i = 0; i <= 17; i++)
		if (dif & (1 << i))
			a = par[a][i];
	if (a != b)
	{
		for(int i=17;i>=0;i--)
			if (par[a][i] && par[a][i] != par[b][i])
			{
				a = par[a][i];
				b = par[b][i];
			}
		a = par[a][0];
	}
	return a;
}
int LCA_K(int st,int en,int p, int k)
{
	int ans;
	int ad = depth[st] - depth[p];
	int bd = depth[en] - depth[p];
	k -= ad;
	if (k == 0) return p;
	if (k > 0)
	{
		bd -= k;
		ans = en;
		for (int i = 17; i >= 0; i--)
		{
			if (bd == 0) break;
			if (bd >= (1 << i))
			{
				ans = par[ans][i];
				bd -= (1 << i);
			}
		}
	}
	else
	{
		k += ad;
		ans = st;
		for (int i = 17; i >= 0; i--)
		{
			if (k == 0) break;
			if (k >= (1 << i))
			{
				ans = par[ans][i];
				k -= (1 << i);
			}
		}
	}
	return ans;
}
int main()
{
	int n,m;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		ll c;
		scanf("%d %d %lld", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 1);
	for (int i = 1; i <= 17; i++)
		for (int j = 1; j <= n; j++)
			par[j][i] = par[par[j][i - 1]][i - 1];
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, k;
		scanf("%d", &a);
		if (a == 1)
		{
			scanf("%d %d", &b, &c);
			int p = LCA(b, c);
			ll sum = dist[b] + dist[c] - 2 * dist[p];
			printf("%lld\n", sum);
		}
		if (a == 2)
		{
			scanf("%d %d %d", &b, &c,&k);
			int p = LCA(b, c);
			printf("%d\n", LCA_K(b,c,p,k-1));
		}
	}
	return 0;
}