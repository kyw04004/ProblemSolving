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
vector<vector<int>> scc;
vector<int> newscc;
stack <int> s;
int V, E, K;
int chk[100001], chk2[100001];
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
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i];
		if (chk2[next] == 0)
			dfs2(next);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &V, &E);
		v.clear();
		v.resize(V + 1);
		for (int i = 1; i <= E; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
		}
		memset(chk, 0, sizeof(chk));
		for (int i = 1; i <= V; i++)
			if (chk[i] == 0)
				dfs(i);
		memset(chk2, 0, sizeof(chk2));
		scc.clear();
		newscc.clear();
		K = 0;
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
	}
	return 0;
}