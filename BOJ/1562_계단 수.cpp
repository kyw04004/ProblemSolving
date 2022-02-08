#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
int dp[11][101][1<<10], N, ans, MOD = 1e9;
int d[2] = { -1,1 };
int go(int now, int depth, int key) {
	if (depth == N) {
		if ((key + 1) == (1 << 10)) return 1;
		else return 0;
	}
	int& ret = dp[now][depth][key];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 2; i++) {
		int next = now + d[i];
		int nkey = (key | (1 << next));
		if (next < 0 || next > 9) continue;
		ret = (ret + go(next, depth + 1, nkey)) % MOD;
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 1; i <= 9; i++)
		ans = (ans + go(i, 1, (1 << i))) % MOD;
	cout << ans;
	return 0;
}