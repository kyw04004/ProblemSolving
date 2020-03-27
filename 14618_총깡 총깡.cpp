#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,st,k,dist[5001],Min=1e9,ans;
map <int, char> M;
priority_queue<P, vector<P>, greater<P>> pq;
vector<vector<P>> v(5001);
void dijk(int s)
{
	dist[st] = 0;
	pq.push({0,st});
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
int main() {
	scanf("%d %d", &n,&m);
	scanf("%d", &st);
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		int a;
		scanf("%d", &a);
		M[a] = 'A';
	}
	for (int i = 1; i <= k; i++)
	{
		int b;
		scanf("%d", &b);
		M[b] = 'B';
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++)
		dist[i] = 1e9;
	dijk(st);
	for (int i = 1; i <= n; i++)
	{
		if (i == st) continue;
		if (dist[i] < Min && (M[i]=='A'|| M[i]=='B'))
			Min = dist[i],ans=i;
		if (Min == dist[i] && Min != 1e9)
			if (M[i] == 'A')
				ans = i;
	}
	if (ans == 0)
		printf("-1");
	else
	{
		printf("%c\n", M[ans]);
		printf("%d\n", Min);
	}
	return 0;
}