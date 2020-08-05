#include<iostream>
#include<cstring>
#include<string>
#include<functional>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int n, dp[100001];
	dp[1] = 2, dp[2] = 2;
	for (int i = 3; i <= 100000; i++) {
		if (i % 2 == 1) dp[i] = 2 * dp[i - 1];
		else dp[i] = dp[i - 1];
		dp[i] %= 16769023;
	}
	cin >> n;
	cout << dp[n];
	return 0;
}
