#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll t, n, m, w, dist[505], inQ[505], cycle[505], chk, visit[505];
queue <ll> q;
vector <pair<ll, ll> > v[505];
void spfa(int src) {
	dist[src] = 0;
	inQ[src] = 1;
	visit[src] = 1;
	q.push(src);
	cycle[src]++;
	while (!q.empty()) {
		ll now = q.front();
		visit[now] = 1;
		q.pop();
		inQ[now] = 0;
		for (int i = 0; i < v[now].size(); i++) {
			ll next = v[now][i].first;
			ll cost = v[now][i].second;
			if (visit[now] && dist[next] > dist[now] + cost) {
				dist[next] = dist[now] + cost;
				if (!inQ[next]) {
					cycle[next]++;
					if (cycle[next] >= n) {
						chk = 1;
						return;
					}
					q.push(next);
					inQ[next] = 1;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 1; i <= n; i++) dist[i] = 1e18;
	spfa(1);
	if (chk == 1) cout << "-1\n";
	else {
		for (int i = 2; i <= n; i++)
			if (!visit[i]) printf("-1\n");
			else printf("%lld\n", dist[i]);
	}
	return 0;
}