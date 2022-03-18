#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
#include<unordered_map>
using namespace std;
typedef long long ll;
int n, w[10005], Max, chk[10005],dp[10005][2];
vector<int> g[10005];
vector<int> ans;
int dfs(int now, bool include) {
	int& ret = dp[now][include];
	if (ret != -1) return ret;
	ret = 0;
	if (include) ret = w[now];
	for(int next : g[now]) {
		if (chk[next]) continue;
		chk[next] = 1;
		if(!include) ret += max(dfs(next, false), dfs(next, true));
		else ret += dfs(next, false);
		chk[next] = 0;
	}
	return ret;
}
void trace(int now, bool include) {
	if (include) ans.push_back(now);
	for (int next : g[now]) {
		if (chk[next]) continue;
		chk[next] = 1;
		if (include) trace(next, 0);
		else
			dp[next][1] > dp[next][0]? trace(next, 1): trace(next, 0);
		chk[next] = 0;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	chk[1] = 1;
	Max = max(dfs(1, 0), dfs(1, 1));
	cout << Max <<'\n';
	dp[1][0] > dp[1][1] ? trace(1, 0) : trace(1, 1);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}