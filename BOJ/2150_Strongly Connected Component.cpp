#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
vector<vector<int>> v;
vector<vector<int>> rv;
vector<vector<int>> scc;
vector<int> newscc;
stack <int> s;
int V, E, K;
int chk[10001], chk2[10001];
void dfs(int now)
{
	chk[now] = 1;
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i];
		if (chk[next] == 0)
			dfs(next);
	}
	s.push(now);
}
void dfs2(int now)
{
	chk2[now] = 1;
	newscc.push_back(now);
	for (int i = 0; i < rv[now].size(); i++)
	{
		int next = rv[now][i];
		if (chk2[next] == 0)
			dfs2(next);
	}
}
int main()
{
	scanf("%d %d", &V, &E);
	v.resize(V + 1);
	rv.resize(V + 1);
	for (int i = 1; i <= E; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		rv[b].push_back(a);
	}
	for (int i = 1; i <= V ;i++)
		if (chk[i] == 0)
			dfs(i);
	while (!s.empty())
	{
		int now = s.top();
		s.pop();
		if (chk2[now] == 1)
			continue;
		newscc.clear();
		dfs2(now);
		K++;
		sort(newscc.begin(), newscc.end());
		scc.push_back(newscc);
	}
	sort(scc.begin(), scc.end());
	printf("%d\n", K);
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < scc[i].size(); j++)
			printf("%d ", scc[i][j]);
		printf("-1\n");
	}
	return 0;
}