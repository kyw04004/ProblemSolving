#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
int N, M, K, edge[301][301],dp[301][301];
int go(int depth, int s) {
	if (s == N) return 0;
	if (depth == M) return -1e9;
	int& ret = dp[depth][s];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = s + 1; i <= N; i++) {
		if (!edge[s][i]) continue;
		ret = max(ret, go(depth + 1, i) + edge[s][i]);
	}
	if (ret <= 0) return -1e9;
	return ret;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) continue;
		edge[a][b] = max(edge[a][b], c);
	}
	cout << go(1,1);
	return 0;
}