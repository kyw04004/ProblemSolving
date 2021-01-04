#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int t, n, arr[200005], dp[200005];
int go(int index) {
	if (index > n) return 0;
	int &ret = dp[index];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, go(index + arr[index]) + arr[index]);
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		int ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++)
			ans = max(ans, go(i));
		cout << ans << '\n';
	}
	return 0;
}