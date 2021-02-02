// LIS - N2
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
int n, ans, dp[105];
pair<int, int> arr[105];
int go(int index) {
	if (index == n) return 0;
	int& ret = dp[index];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = index + 1; i < n; i++) {
		if (arr[index].second < arr[i].second)
			ret = max(ret, go(i) + 1);
	}
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		ans = max(ans, go(i));
	cout << n-ans;
	return 0;
}