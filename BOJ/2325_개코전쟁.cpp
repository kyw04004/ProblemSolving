//다익스트라
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int n, m, dist[1005], ans;
vector<pair<int,int>> v[1005];
vector<pair<int, int>> delCandi;
priority_queue<p, vector<p>, greater<p>> pq;
pair<int, int> impossible;
void dijk() {
	for (int i = 1; i <= n; i++)
		dist[i] = 1e9;
	dist[1] = 0; 
	pq.push({0,1});
	while (!pq.empty()) {
		int now = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (val > dist[now]) continue;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextcost = v[now][i].second;
			if (impossible.first == now && impossible.second == next) continue;
			if (impossible.second == now && impossible.first == next) continue;
			if (dist[next] > dist[now] + nextcost) {
				dist[next] = dist[now] + nextcost;
				pq.push({ dist[next], next });
			}
		}
	}
}
void delCandiSave() {
	int now = n;
	while (now != 1) {
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextcost = v[now][i].second;
			if (dist[now] - nextcost == dist[next]) {
				delCandi.push_back({now, next});
				now = next;
				break;
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dijk();
	delCandiSave();
	for (int i = 0; i < delCandi.size(); i++) {
		impossible = delCandi[i];
		dijk();
		ans = max(ans, dist[n]);
	}
	cout << ans;
	return 0;
}