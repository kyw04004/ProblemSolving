#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
ll n, m, dist[501];
vector<vector<p>> v;
bool bellman(int st) {
	for (int i = 1; i <= n; i++) dist[i] = 1e18;
	dist[st] = 0;
	bool cycle = false;
	for(ll k=1;k<=n;k++)
		for (ll i = 1; i <= n; i++) {
			if (dist[i] == 1e18) continue;
			for (ll j = 0; j < v[i].size(); j++) {
				ll next = v[i][j].first;
				ll nextCost = v[i][j].second;
				if (dist[next] > dist[i] + nextCost) {
					dist[next] = dist[i] + nextCost;
					if (k == n) cycle = true;
				}
			}
		}
	return cycle;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		//v[b].push_back({ a,c });
	}
	if (bellman(1)) cout << "-1\n";
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == 1e18) cout << "-1\n";
			else cout << dist[i] << '\n';
		}
	}
	return 0;
}