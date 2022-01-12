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
priority_queue<int, vector<int>, less<int>> dist[1001];
int n, m, k;
void dijk(int st) {
	priority_queue<p, vector<p>, greater<p>> pq;
	dist[st].push(0);
	pq.push({ 0, st });
	while (!pq.empty()) {
		int now = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = v[now][i].second;
			if (dist[next].size() < k || (dist[next].top() > (val + nextCost))) {
				if (dist[next].size() == k) dist[next].pop();
				dist[next].push(val + nextCost);
				pq.push({ val + nextCost, next });
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	dijk(1);
	for (int i = 1; i <= n; i++) {
		if (dist[i].size() == k) cout << dist[i].top() << '\n';
		else cout << "-1\n";
	}
	return 0;
}