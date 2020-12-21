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
char c[6];
int K,n,alpha[27];
int chk[27], chk2[27];
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
	while (1)
	{
		scc.clear();
		v.clear();
		rv.clear();
		v.resize(27);
		rv.resize(27);
		memset(chk, 0, sizeof(chk));
		memset(chk2, 0, sizeof(chk2));
		memset(alpha, 0, sizeof(alpha));
		K = 0;
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < 6; i++)
			{
				scanf(" %c", &c[i]);
				alpha[c[i] - 'A'] = 1;
			}
			for (int i = 0; i < 5; i++)
			{
				v[c[5] - 'A'].push_back(c[i] - 'A');
				rv[c[i] - 'A'].push_back(c[5] - 'A');
			}
		}
		for (int i = 0; i <= 25; i++)
			if (chk[i] == 0 && alpha[i] == 1)
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
		for (int i = 0; i < K; i++)
		{
			for (int j = 0; j < scc[i].size(); j++)
				printf("%c ", scc[i][j] + 'A');
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}