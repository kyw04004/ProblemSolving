#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<functional>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
vector<vector<pair<int, int>>> v(1001);
stack <pair<int, int>> s;
int V, E, a, b, c, sum, cnt,ans;
int chk[1001];
void prim(int st)
{
	pq.push({ { 0, st }, 1 });
	while (!pq.empty())
	{
		int here = pq.top().first.second;
		int cost = pq.top().first.first;
		int before = pq.top().second;
		pq.pop();
		if (chk[here] == 1) continue;
		chk[here] = 1;
		sum += cost;
		if (cost > 0)
		{
			cnt++;
			s.push({ here, before });
		}
		for (int i = 0; i < v[here].size(); i++)
		{
			int next = v[here][i].first;
			int nextcost = v[here][i].second;
			if (chk[next] == 0)
			{
				pq.push({ { nextcost,next },here });
			}
		}
	}
}
int main()
{
	cin >> V >> E;
	for (int i = 1; i <= E; i++)
	{
		cin >> a >> b;
		v[a].push_back({ b,0 });
		v[b].push_back({ a,0 });
	}
	for(int i=1;i<=V;i++)
		for (int j = 1; j <= V; j++)
		{
			cin >> c;
			if (i >= 2 && j >= 2)
				v[i].push_back({ j,c });
		}
	if (V == 1)
		printf("0 0\n");
	else
	{
		prim(2);
		printf("%d %d\n", sum, cnt);
		while (!s.empty())
		{
			printf("%d %d\n", s.top().first, s.top().second);
			s.pop();
		}
	}
	return 0;
}