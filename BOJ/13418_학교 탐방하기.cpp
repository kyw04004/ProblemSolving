#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq2;
vector<vector<pair<int, int>>> v(1001);
int V, E, a, b, c, t, sum, ans1, ans2;
int chk[1001];
void prim0(int st)
{
	pq.push({ 1, st });
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (chk[here] == 1) continue;
		chk[here] = 1;
		if (cost == 0)
			sum += 1;
		for (int i = 0; i < v[here].size(); i++)
		{
			int next = v[here][i].first;
			int nextcost = v[here][i].second;
			if (chk[next] == 0)
				pq.push({ nextcost,next });
		}
	}
}
void prim1(int st)
{
	pq2.push({ 1, st });
	while (!pq2.empty())
	{
		int here = pq2.top().second;
		int cost = pq2.top().first;
		pq2.pop();
		if (chk[here] == 1) continue;
		chk[here] = 1;
		if (cost == 0)
			sum += 1;
		for (int i = 0; i < v[here].size(); i++)
		{
			int next = v[here][i].first;
			int nextcost = v[here][i].second;
			if (chk[next] == 0)
				pq2.push({ nextcost,next });
		}
	}
}
int main()
{

	scanf("%d%d", &V, &E);
	for (int i = 1; i <= E + 1; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	prim0(0);
	ans1 = sum * sum;
	sum = 0;
	memset(chk, 0, sizeof(chk));
	prim1(0);
	ans2 = sum * sum;
	printf("%d", ans1 - ans2);
	return 0;
}