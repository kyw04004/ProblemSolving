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
ll N, K, height[17], dp[17][1<<16];
ll dfs(ll now, ll key) {
	if (key == ((1<<N) -1)) return 1;
	ll &ret = dp[now][key];
	if (ret != -1) return ret;
	ret = 0;
	for (ll i = 1; i <= N; i++)
		if ((key == 0 || abs(height[now] - height[i]) > K) && ((key & (1 << (i - 1))) == 0))
			ret += dfs(i, key | (1 << i - 1));
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> height[i];
	cout << dfs(0, 0);
	return 0;
}