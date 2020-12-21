#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
#include<vector>
using namespace std;
typedef pair <int, int> P;
int n, m, a, b, cost,k;
int dist[20001];
vector<vector<P>> v(20001);
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
			if (dist[next] > dist[here] + nextcost)
			{
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],next});
			}
		}
	}
}
int main()
{
	scanf("%d %d %d", &n, &m,&k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &cost);
		v[a].push_back({ b, cost });
	}
	dijk(k);
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == 1e9)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}