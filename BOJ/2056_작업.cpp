#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int n, ind[10001], dp[10001],val[10001], ans;
vector<int> v[10001];
queue <int> q;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int cnt, i = 1; i <= n; i++) {
		cin >> val[i] >> cnt;
		dp[i] = val[i];
		for (int j = 1; j <= cnt; j++) {
			int node; cin >> node;
			v[node].push_back(i);
			ind[i]++;
		}
	}
	for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			dp[next] = max(dp[now] + val[next], dp[next]);
			ind[next]--;
			if (!ind[next]) q.push(next);
		}
	}
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans;
	return 0;
}