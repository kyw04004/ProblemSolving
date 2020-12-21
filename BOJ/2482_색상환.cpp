#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, k, dp[1001][1001];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) dp[i][1] = i;

	for (int i = 4; i <= n; i++) 
		for (int j = 2; j <= (n/2); j++) 
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % 1000000003;;
	cout << dp[n][k];
	return 0;
}