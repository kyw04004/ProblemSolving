#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<pair<int, int>>> v;
long long V, E, a, b, c, t, sum, cnt, M;
int chk[200001];
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
	while (1) {
		scanf("%lld%lld", &V, &E);
		if (V == 0 && E == 0) break;
		v.clear();
		v.resize(V + 1);
		M = 0;
		memset(chk, 0, sizeof(chk));
		sum = 0;
		for (int i = 1; i <= E; i++)
		{
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
			M += c;
		}
		prim(0);
		printf("%lld\n", M - sum);
	}
	return 0;
}