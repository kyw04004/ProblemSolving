#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> p;
int T, N, D, C, dp[10005], ansCnt, ansTime;
vector<vector<p>> graph;
priority_queue<p, vector<p>, greater<p>> pq;
void dijk(int st) {
	dp[st] = 0;
	ansCnt = 1;
	ansTime = 0;
	pq.push({ dp[st], st });
	while (!pq.empty()) {
		int now = pq.top().second;
		int nowTime = pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;
			if (dp[next] == 1e9) ansCnt++;
			if (dp[next] > dp[now] + nextCost) {
				dp[next] = dp[now] + nextCost;
				pq.push({dp[next], next});
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
		cin >> N >> D >> C;
		graph.clear();
		graph.resize(N + 1);
		for (int i = 1; i <= N; i++) dp[i] = 1e9;
		for (int i = 0; i < D; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			graph[b].push_back({ a,s });
		}
		dijk(C);
		for (int i = 1; i <= N; i++) {
			if (dp[i] == 1e9) continue;
			ansTime = max(ansTime, dp[i]);
		}
		cout << ansCnt << ' ' << ansTime << '\n';
	}
	return 0;
}