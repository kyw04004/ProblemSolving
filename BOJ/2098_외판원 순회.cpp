#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int n, ans=1e9, dp[17][1<<16], w[17][17];
int go(int st, int now, int key) {
	if (key == ((1<<n)-1)) {
		if (w[now][st] == 0) return 1e9;
		return w[now][st];
	}
	int &ret = dp[now][key];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 1; i <= n; i++) {
		if (w[now][i] == 0) continue;
		int nkey = (key | (1 << (i - 1)));
		if (!(key & (1 << (i - 1)))) {
			ret = min(ret, go(st, i, nkey) + w[now][i]);
		}
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> w[i][j];
	for (int i = 1; i <= n; i++) {
		memset(dp, -1, sizeof(dp));
		ans = min(ans, go(i, i, 1 << (i - 1)));
	}
	cout << ans;
	return 0;
}