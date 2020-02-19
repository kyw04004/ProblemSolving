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
vector<pair<int, int>> bs;
stack <int> s;
int V, K, t;
int chk[303], chk2[303];
int output[303][303]; // 노드 간선
int ans[303][303]; // scc 간선
int arr[303]; // scc 번호

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
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &V);
		memset(chk, 0, sizeof(chk));
		memset(chk2, 0, sizeof(chk2));
		memset(arr, 0, sizeof(arr));
		memset(ans, 0, sizeof(ans));
		memset(output, 0, sizeof(output));
		K = 0;
		bs.clear();
		scc.clear();
		v.clear();
		rv.clear();
		v.resize(V + 1);
		rv.resize(V + 1);
		for (int i = 1; i <= V; i++)
			for(int j = 1; j <= V; j++)
		{
			char a;
			scanf(" %1c", &a);
			if (i == j)
				continue;
			if (a == '1')
			{
				output[i][j] = 1;
				v[i].push_back(j);
				rv[j].push_back(i);
			}
		}
		for (int i = 1; i <= V; i++)
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
			scc.push_back(newscc);
			for (int i = 0; i < newscc.size(); i++)
			{
				arr[newscc[i]] = scc.size();
				if (newscc.size() == 1)
					continue;
				if (i == newscc.size() - 1)
					bs.push_back({ newscc[i], newscc[0] });
				else
					bs.push_back({ newscc[i], newscc[i + 1] });
				K++;
			}
		}

		for(int i = 1; i <= V; i++) // scc 간선 체크
			for (int j = 1; j <= V; j++)
			{
				if (arr[i] == arr[j]) continue;
				if (output[i][j] == 1)
					ans[arr[i]][arr[j]] = 1;
			}

		for(int k = 1; k <= scc.size(); k++) // scc 불필요 간선 삭제
			for (int i = 1; i <= scc.size(); i++)
				for (int j = 1; j <= scc.size(); j++)
				{
					if (i == k || k == j || i == j) continue;
					if (ans[i][j] && (ans[i][k] && ans[k][j]))
						ans[i][j] = 0;
				}

		for (int i = 1; i <= scc.size(); i++)
			for (int j = 1; j <= scc.size(); j++)
			{
				if (i == j) continue;
				if (ans[i][j] == 1)
				{
					bs.push_back({ scc[i - 1][0], scc[j - 1][0] });
					K++;
				}
			}

		printf("%d\n", K);
		for (int i = 0; i < bs.size(); i++)
			printf("%d %d\n", bs[i].first, bs[i].second);
		printf("\n");
	}
	return 0;
}