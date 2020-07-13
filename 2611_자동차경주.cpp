#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
priority_queue <pair<int,int>, vector<pair<int, int>> ,less<pair<int, int>>> pq;
vector<pair<int,int>> v[1001];
stack <int> s;
int n, m, dist[1001], path[1001];
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 0; i < v[1].size(); i++)
	{
		int next = v[1][i].first;
		int nextcost = v[1][i].second;
		dist[next] = nextcost;
		pq.push({ dist[next], next });
	}
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[here].size(); i++) {
			int next = v[here][i].first;
			int nextcost = v[here][i].second;
			if (dist[next] < dist[here] + nextcost) {
				path[next] = here;
				dist[next] = dist[here] + nextcost;
				if(next != 1) pq.push({ dist[next], next });
			}
		}
	}
	printf("%d\n", dist[1]);
	int now = 1;
	while (1) {
		s.push(now);
		now = path[now];
		if (now == 0) break;
	}
	s.push(1);
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}