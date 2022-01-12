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
int n, m, x, dist1[1005], dist2[1005];
vector <vector<p>> v, rv;
void dijk1(int st) {
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push({ 0, x });
	for (int i = 1; i <= n; i++) dist1[i] = 1e9;
	dist1[x] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int sum = pq.top().first;
		pq.pop();
		if (sum > dist1[now]) continue;
		for (int i = 0; i < rv[now].size(); i++) {
			int next = rv[now][i].first;
			int nextCost = rv[now][i].second;
			if (dist1[next] > sum + nextCost) {
				dist1[next] = sum + nextCost;
				pq.push({ dist1[next], next });
			}
		}
	}
}
void dijk2(int st) {
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push({ 0, x });
	for (int i = 1; i <= n; i++) dist2[i] = 1e9;
	dist2[x] = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		int sum = pq.top().first;
		pq.pop();
		if (sum > dist2[now]) continue;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = v[now][i].second;
			if (dist2[next] > sum + nextCost) {
				dist2[next] = sum + nextCost;
				pq.push({ dist2[next], next });
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> x;
	v.resize(n + 1);
	rv.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		rv[b].push_back({ a,c });
	}
	dijk1(x);
	dijk2(x);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dist1[i] + dist2[i]);
	cout << ans;
	return 0;
}