#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int n, m, a, b,v;
int chk1[1001], chk2[1001];
queue <int> q;
vector <vector<int>> adj(1001);
void dfs(int now)
{
	chk1[now] = 1;
	printf("%d ", now);
	for (int i = 0; i<adj[now].size(); i++)
	{
		int next = adj[now][i];
		if (chk1[next] != 1)
			dfs(next);
	}
}
void bfs(int now)
{
	chk2[now] = 1;
	q.push(now);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		printf("%d ", here);
		for (int i = 0; i < adj[here].size(); i++)
		{
			int next = adj[here][i];
			if (chk2[next] != 1)
			{
				chk2[next] = 1;
				q.push(next);
			}
		}
	}
}
int main()
{
	cin >> n >> m >> v;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	dfs(v);
	printf("\n");
	bfs(v);
	printf("\n");
	return 0;
}