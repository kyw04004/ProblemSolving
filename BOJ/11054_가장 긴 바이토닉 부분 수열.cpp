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
int n, arr[1005], dp[1005][2], ans;
int go(int index, int updown) {
	if (index == n) return 0;
	int& ret = dp[index][updown];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = index + 1; i < n; i++) {
		if (!updown && arr[index] < arr[i])
			ret = max(ret, go(i,0) + 1);
		if (arr[index] > arr[i])
			ret = max(ret, go(i, 1) + 1);
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++)
		ans = max(ans, go(i, 0));
	cout << ans;
	return 0;
}