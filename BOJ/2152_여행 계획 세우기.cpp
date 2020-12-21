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
vector<vector<int>> big;
vector<int> newscc;
stack <int> s;
vector <pair<int, int>> gan;
queue <int> q;
int V, E, S, T;
int chk[10001], chk2[10001];
int arr[10001], val[10001];
int ans[10001], out[10001], go[10001];
void dfs(int now) // 스택에 담기
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
void dfs2(int now) // scc 묶기
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
	scanf("%d %d %d %d", &V, &E, &S, &T);
	v.resize(V + 1);
	rv.resize(V + 1);
	big.resize(V + 1);
	for (int i = 1; i <= E; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		gan.push_back({ a,b });
		v[a].push_back(b);
		rv[b].push_back(a);
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
			arr[newscc[i]] = scc.size();
		val[scc.size()] = newscc.size();
	}
	for (int i = 0; i < gan.size(); i++)
	{
		if (arr[gan[i].first] == arr[gan[i].second])
			continue;
		big[arr[gan[i].first]].push_back(arr[gan[i].second]);
		out[arr[gan[i].second]]++;
	}
	for (int i = 1; i <= scc.size(); i++) {
		ans[i] = val[i];
		if (out[i] == 0)
			q.push(i);
		if (i == arr[S])
			go[i] = 1;
	}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < big[here].size(); i++) {
			int next = big[here][i];
			if (go[here])
			{
				ans[next] = max(ans[next], ans[here] + val[next]);
				go[next] = 1;
			}
			out[next] -= 1;
			if (out[next] == 0)
				q.push(next);
		}
	}
	if (go[arr[T]])
		printf("%d\n", ans[arr[T]]);
	else
		printf("0\n");
	return 0;
}