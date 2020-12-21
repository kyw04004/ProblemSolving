#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<deque>
#include<stack>
#include<functional>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll v, e, dest[15], chk[10005], st, dist[10005], dist2[10005];
ll Min = 1e18, time;
vector<pair<ll, ll>> road[10005];
void dijk(ll s, ll dist[]) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
		greater<pair<ll, ll>>> pq;
	dist[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		ll cost = pq.top().first;
		ll here = pq.top().second;
		pq.pop();
		if (cost > dist[here]) continue;
		for (ll i = 0; i < road[here].size(); i++) {
			ll next = road[here][i].first;
			ll nextcost = road[here][i].second;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],next });
			}
		}
	}
}
int main() {
	cin >> v >> e;
	for (ll i = 1; i <= e; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
		road[b].push_back({ a,c });
	}
	for (ll i = 1; i <= v; i++) dist[i] = 1e18;
	for (ll i = 1; i <= 10; i++) cin >> dest[i];
	cin >> st;
	if (dest[1] == st) chk[st] = 1;
	dijk(st, dist);
	ll sindex = 1;
	ll dindex = 2;
	while (dindex <= 10) {
		for (ll i = 1; i <= v; i++) dist2[i] = 1e18;
		dijk(dest[sindex], dist2);
		if (dist2[dest[dindex]] != 1e18) {
			time += dist2[dest[dindex]];
			sindex = dindex;
			if (dist[dest[dindex]] != 1e18)
				if (dist[dest[dindex]] <= time)
					chk[dest[dindex]] = 1;
		}
		dindex++;
	}
	for (ll i = 1; i <= v; i++)
		if (chk[i]) Min = min(Min, i);
	if (Min == 1e18) cout << -1;
	else cout << Min;
	return 0;
}