#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int N, M, useM[105], c[105], dp[105][10005];
int dfs(int depth, int cost) {
	if (depth == N) return 0;
	int &ret = dp[depth][cost];
	if (ret != -1) return ret;
	ret = 0;
	if(cost - c[depth] >= 0)
		ret = max(ret, dfs(depth + 1, cost - c[depth]) + useM[depth]);
	ret = max(ret, dfs(depth + 1, cost));
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> useM[i];
	for (int i = 0; i < N; i++) cin >> c[i];
	dfs(0, 0);
	for (int i = 0; i<=10000; i++) {
		int memory = dfs(0, i);
		if (memory >= M) {
			cout << i;
			break;
		}
	}
	return 0;
}