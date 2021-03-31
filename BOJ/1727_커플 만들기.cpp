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
int n, m, narr[1005], marr[1005], dp[1005][1005];
int go(int a, int b) {
	if (a == n) return 0;
	int &ret = dp[a][b];
	if (ret != -1) return ret;
	ret = 1e9;
	if (b < m) {
		ret = min(ret, go(a + 1, b + 1) + abs(narr[a + 1] - marr[b + 1]));
		ret = min(ret, go(a, b + 1));
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> narr[i];
	for (int i = 1; i <= m; i++) cin >> marr[i];
	if (n > m) {
		swap(n, m);
		swap(narr, marr);
	}
	sort(narr + 1, narr + n + 1);
	sort(marr + 1, marr + m + 1);
	cout << go(0, 0);
	return 0;
}