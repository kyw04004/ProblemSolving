#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
int n, m, dist[1001], chk[1001], path[1001];
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) dist[i] = 1e9;
	pq.push({ 0,1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextcost = v[now][i].second;
			if (dist[next] > dist[now] + nextcost) {
				dist[next] = dist[now] + nextcost;
				path[next] = now;
				pq.push({dist[next], next});
			}
		}
	}
	printf("%d\n", n - 1);
	for (int i = 2; i <= n; i++)
		printf("%d %d\n", i, path[i]);
	return 0;
}