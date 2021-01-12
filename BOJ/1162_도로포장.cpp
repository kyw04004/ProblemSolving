#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
ll n, m, k, dist[10005][25], ans = 1e18;
vector<pair<ll, ll>> v[10005];
priority_queue<pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll>>, less<pair<pair<ll, ll>, ll>>> pq;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= k; j++)
			dist[i][j] = 1e18;
	for (int i = 1; i <= m; i++) {
		ll a, b, c; cin >> a >> b >> c;
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
	}
	dist[1][0] = 0;
	pq.push({ {0, 1},0 });
	while (!pq.empty()) {
		ll now = pq.top().first.second;
		ll cost = pq.top().first.first;
		ll cnt = pq.top().second;
		pq.pop();
		if (cost > dist[now][cnt]) continue;
		for (int i = 0; i < v[now].size(); i++) {
			ll next = v[now][i].second;
			ll nextcost = v[now][i].first;
			if (dist[next][cnt] > dist[now][cnt] + nextcost) {
				dist[next][cnt] = dist[now][cnt] + nextcost;
				pq.push({ {dist[next][cnt], next},cnt });
			}
			if ((cnt < k) && (dist[next][cnt+1] > dist[now][cnt])) {
				dist[next][cnt + 1] = dist[now][cnt];
				pq.push({ {dist[next][cnt+1], next}, cnt+1 });
			}
		}
	}
	for (int i = 0; i <= k; i++) ans = min(ans, dist[n][i]);
	cout << ans;
	return 0;
}