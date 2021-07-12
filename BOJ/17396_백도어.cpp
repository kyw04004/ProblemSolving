#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, m, canShow[100005], dist[100005];
vector<P> v[100005];
priority_queue<P, vector<P>, greater<P>> pq;
ll dijk() {
	dist[0] = 0;
	pq.push({ 0,0 });
	while (!pq.empty()) {
		ll now = pq.top().second;
		ll cost = pq.top().first;
		pq.pop();
		if (cost > dist[now]) continue;
		if (now == n - 1) return cost;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = v[now][i].second;
			if (next != n - 1 && canShow[next]) continue;
			if (dist[next] > dist[now] + nextCost) {
				dist[next] = dist[now] + nextCost;
				pq.push({ dist[next], next });
			}
		}
	}
	return -1;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> canShow[i];
		dist[i] = 1e18;
	}
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	cout << dijk();
	return 0;
}