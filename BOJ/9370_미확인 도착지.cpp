#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int T, n, m, t, s, g, h, dist[2005], dist2[2005];
vector<vector<pair<int, int>>> v;
void dijk(int st) {
	priority_queue<pair<int, int>, vector<pair<int, int>>,
		greater<pair<int, int>>> pq;
	dist[st] = 0;
	pq.push({ 0,st });
	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cost > dist[now]) continue;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextcost = v[now][i].second;
			if (dist[next] > dist[now] + nextcost) {
				dist[next] = dist[now] + nextcost;
				pq.push({dist[next], next});
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		v.clear();
		v.resize(n + 1);
		int midcost;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
			v[b].push_back({ a,c });
			if (a == g && b == h || a == h && b == g) midcost = c;
		}
		for (int i = 1; i <= n; i++) dist[i] = 1e9;
		dijk(s);
		int mid;
		if (dist[g] > dist[h]) mid = h;
		else mid = g;
		for (int i = 1; i <= n; i++)
			dist2[i] = dist[i], dist[i] = 1e9;
		if (mid == h) dijk(g);
		else dijk(h);
		dijk(mid);
		vector<int> ans;
		for (int i = 0; i < t; i++) {
			int d; cin >> d;
			if (dist2[d] == dist2[mid] + dist[d] + midcost) ans.push_back(d);
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << ' ';
		cout << '\n';
	}
	return 0;
}