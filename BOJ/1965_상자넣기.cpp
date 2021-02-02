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
int n, arr[1005], ans, dp[1005];
int go(int index) {
	if (index == n) return 0;
	int& ret = dp[index];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = index+1; i < n; i++) {
		if (arr[index] < arr[i])
			ret = max(ret, go(i) + 1);
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		ans = max(ans, go(i));
	cout << ans;
	return 0;
}