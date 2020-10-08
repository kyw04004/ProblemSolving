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
int t, n, dp[2][1005][1005], arr[1005];
int go(int st, int en, int turn) {
	if (st == en) {
		if (!turn) return arr[st];
		else return 0;
	}
	int &ret = dp[turn][st][en];
	if (ret != -1) return ret;
	ret = 0;
	if (!turn) ret = max(go(st + 1, en, 1) + arr[st], go(st, en - 1, 1) + arr[en]);
	else ret = min(go(st + 1, en, 0), go(st, en - 1, 0));
	return ret;
}
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < n; i++) cin >> arr[i];
		printf("%d\n", go(0, n - 1, 0));
	}
	return 0;
}