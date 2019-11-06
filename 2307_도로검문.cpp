#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
#include<vector>
#include<stack>
using namespace std;
typedef pair <int, int> P;
int n, m, a, b, cost,cnt,x,y;
int comp1, comp2;
int dist[1001];
int past[1001];
vector<vector<P>> v(1001);
stack <pair<int,int>> s;
priority_queue<P, vector<P>, greater<P>> pq;
void dijk(int st)
{
	for (int i = 1; i <= n; i++)
		dist[i] = 1e9;
	dist[st] = 0;
	pq.push({ 0,st });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (cost > dist[here]) continue;
		for (int i = 0; i < v[here].size(); i++)
		{
			int next = v[here][i].first;
			int nextcost = v[here][i].second;
			if (!s.empty())
			{
				x = s.top().first;
				y = s.top().second;
			}
			if (x == here && y == next&&!s.empty()) continue;
			if (dist[next] > dist[here] + nextcost)
			{
				dist[next] = dist[here] + nextcost;
				past[next] = here;
				pq.push({ dist[next],next });
			}
		}
	}
}
void go(int a, int b)
{
	if (b == a)
		return;
	if (past[b] != 0)
	{
		s.push({past[b],b});
		go(a, past[b]);
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &cost);
		v[a].push_back({ b, cost });
		v[b].push_back({ a, cost });
	}
	dijk(1);
	comp1 = dist[n];
	go(1, n);
	while (!s.empty())
	{
		memset(dist, 0, sizeof(dist));
		dijk(1);
		s.pop();
		if (dist[n] > comp2)
			comp2 = dist[n];
	}
	if (comp2 == 1e9 || comp1 == 1e9)
		printf("-1");
	else
		printf("%d", comp2 - comp1);
	return 0;
}