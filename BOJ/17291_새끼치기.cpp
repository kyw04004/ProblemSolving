#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dp[21], born[21];
int main() {
	born[1] = 1, born[2] = 1, born[3] = 2, born[4] = 4;
	dp[1] = 1, dp[2] = 2, dp[3] = 4, dp[4] = 7;
	for (int i = 5; i <= 20; i++) {
		if (i % 2 == 1) dp[i] = 2 * dp[i - 1];
		else dp[i] = 2 * dp[i - 1] - born[i - 3] - born[i - 4];
		born[i] = dp[i - 1];
	}
	int n;
	cin >> n;
	cout << dp[n];
	return 0;
}