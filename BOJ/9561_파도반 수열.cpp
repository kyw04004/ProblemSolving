#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int main() {
	ll t, n, dp[101] = { 0, };
	dp[1] = 1, dp[2] = 1, dp[3] = 1, dp[4] = 2, dp[5] = 2;
	for (int i = 6; i <= 100; i++)
		dp[i] = dp[i - 1] + dp[i - 5];
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}