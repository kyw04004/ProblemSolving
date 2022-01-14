#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<int, p>pp;
int n, m, dist[50005];
vector<vector<p>> v;
void dijk(int st) {
	for (int i = 1; i <= n; i++) dist[i] = 1e9;
	dist[st] = 0;
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push({ 0, st });
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cost > dist[now]) continue;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = v[now][i].second;
			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				pq.push({ dist[next], next });
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dijk(1);
	cout << dist[n];
	return 0;
}