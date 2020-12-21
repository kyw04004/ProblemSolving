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
int n, m, a, b, cost, k;
int af, bf;
int dist[801];
vector<vector<P>> v(801);
priority_queue<P, vector<P>, greater<P>> pq;
void dijk(int st)
{
	for (int i = 1; i <= n; i++)
		dist[i] = 1e8;
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
			int nextcost = v[here][i].second;
			int next = v[here][i].first;
			if (dist[next] > dist[here] + nextcost)
			{
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],next });
			}
		}
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
	scanf("%d%d", &a, &b);
	dijk(1);
	af += dist[a];
	dijk(a);
	af += dist[b];
	dijk(b);
	af += dist[n];
	dijk(1);
	bf += dist[b];
	dijk(b);
	bf += dist[a];
	dijk(a);
	bf += dist[n];
	if (af >= 1e8 && bf >= 1e8)
		printf("-1");
	else if (af > bf)
		printf("%d", bf);
	else
		printf("%d", af);
	return 0;
}