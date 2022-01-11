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
vector<vector<p>> v;
vector<vector<int>> path;
int n, m, dist[505], chk[505][505];
void dijk(int st) {
	priority_queue<p, vector<p>, greater<p>> pq;
	for (int i = 0; i < n; i++) 
		dist[i] = 1e9;
	dist[st] = 0;
	pq.push({ 0, st });
	while (!pq.empty()) {
		int now = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (val > dist[now]) continue;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = v[now][i].second;
			if (chk[now][next]) continue;
			if (dist[next] > dist[now] + nextCost) {
				dist[next] = dist[now] + nextCost;
				pq.push({ dist[next], next });
				path[next].clear();
			}
			if(dist[next] == (dist[now] + nextCost))
				path[next].push_back(now);
		}
	}
}
void dfs(int now, int s) {
	if (now == s) return;
	for (int i = 0; i < path[now].size(); i++) {
		int next = path[now][i];
		if (chk[next][now]) continue;
		chk[next][now] = 1;
		dfs(next, s);
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (true) {
		memset(chk, 0, sizeof(chk));
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		v.clear();
		path.clear();
		v.resize(n + 1);
		path.resize(n + 1);
		int s, d; cin >> s >> d;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			v[a].push_back({ b,c });
		}
		dijk(s);
		dfs(d, s);
		dijk(s);
		if (dist[d] == 1e9) cout << "-1\n";
		else cout << dist[d] << '\n';
	}
	return 0;
}