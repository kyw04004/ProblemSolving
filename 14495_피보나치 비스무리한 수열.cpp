#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
#include<queue>
typedef long long ll;
using namespace std;
ll n, dp[117];
int main() {
	dp[1] = 1, dp[2] = 1, dp[3] = 1;
	cin >> n;
	for (int i = 4; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 3];
	cout << dp[n];
	return 0;
}