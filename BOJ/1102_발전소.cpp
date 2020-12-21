#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
int n, p, Map[17][17], dp[17][(1 << 16)];
int YN[17], startkey, cnt, ans = 1e9;
int go(int now, int cnt, int key) {
	if (cnt >= p) return 0;
	int &ret = dp[now][key];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 1; i <= n; i++) {
		if (i == now) continue;
		int nkey = (key | (1 << (i - 1)));
		int nextval = Map[now][i];
		if (!(key & (1 << (i - 1))))
			for (int j = 1; j <= n; j++)
				if (nkey & (1 << (j - 1)))
					ret = min(ret, go(j, cnt + 1, nkey) + nextval);
	}
	return ret;
}
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> Map[i][j];
	for (int i = 1; i <= n; i++) {
		char a;
		cin >> a;
		if (a == 'Y') {
			cnt++, startkey |= (1 << (i - 1));
			YN[i] = 1;
		}
	}
	cin >> p;
	for (int i = 1; i <= n; i++)
		if (YN[i] == 1) {
			int com = go(i, cnt, startkey);
			ans = min(ans, com);
		}
	if (ans == 1e9) ans = -1;
	if (!cnt && !p) ans = 0;
	cout << ans << "\n";
	return 0;
}