#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int N, arr[1005], dp[1005], ans;
int go(int idx) {
	int &ret = dp[idx];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = idx + 1; i < N; i++)
		if (arr[idx] < arr[i]) ret = max(ret, go(i) + 1);
	return ret;
}
int main() 	{
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++)
		ans = max(ans, go(i));
	cout << ans << '\n';
	for (int i = 0; i < N; i++) {
		if (dp[i] == ans) {
			cout << arr[i] << ' ';
			ans--;
		}
	}
	return 0;
}