#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<pair<int, int>>> v(10001);
int V, E, a, b, c, t, sum, cnt;
int chk[10001];
void prim(int st)
{
	pq.push({ 0, st });
	while (!pq.empty())
	{
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (chk[here] == 1) continue;
		chk[here] = 1;
		sum += cost;
		for (int i = 0; i < v[here].size(); i++)
		{
			int next = v[here][i].first;
			int nextcost = v[here][i].second;
			if (chk[next] == 0)
				pq.push({ nextcost,next });
		}
	}
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &V, &E);
		memset(chk, 0, sizeof(chk));
		sum = 0;
		v.clear();
		v.resize(V + 1);
		for (int i = 1; i <= E; i++)
		{
			cin >> a >> b;
			v[a].push_back({ b,1 });
			v[b].push_back({ a,1 });
		}
		prim(1);
		printf("%d\n", sum);
	}
	return 0;
}