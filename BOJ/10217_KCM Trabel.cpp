#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
int T, N, M, K, u, v, c, d, ans;
int dp[105][100005];//dp[위치][비용] = 거리
struct element {
	int time;
	int cost;
	int node;
};
struct compare {
	bool operator() (element A, element B) {
		return A.time > B.time;
	}
};
vector<vector<element>> grape;
void dijk() {
	priority_queue<element, vector<element>, compare> pq;
	dp[1][M] = 0;
	pq.push({0, M, 1});
	while (!pq.empty()) {
		int node = pq.top().node;
		int restCost = pq.top().cost;
		int time = pq.top().time;
		pq.pop();
		if (time > dp[node][restCost]) continue;
		if (node == N) {
			ans = min(ans, time);
			continue;
		}
		for (int i = 0; i < grape[node].size(); i++) {
			int next = grape[node][i].node;
			int nextCost = grape[node][i].cost;
			int nextTime = grape[node][i].time;
			if (restCost - nextCost < 0) continue;
			if (dp[next][restCost - nextCost] > time + nextTime) {
				dp[next][restCost - nextCost] = time + nextTime;
				pq.push({dp[next][restCost - nextCost], restCost - nextCost, next});
			}
		}
	}
}
int main() {
	cin >> T;
	while (T--) {
		ans = 1e9;
		for (int i = 1; i <= 100; i++)
			for (int j = 0; j <= 10000; j++)
				dp[i][j] = 1e9;
		cin >> N >> M >> K;
		grape.clear();
		grape.resize(N + 1);
		for (int i = 0; i < K; i++) {
			cin >> u >> v >> c >> d;
			grape[u].push_back({ d,c,v });
		}
		dijk();
		if (ans == 1e9) cout << "Poor KCM\n";
		else cout << ans << '\n';
	}
	return 0;
}