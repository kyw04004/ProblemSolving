#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, dp[1005][15], mod = 10007, sum;
int main() {
	for (int i = 0; i <= 9; i++) dp[1][i] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++) 
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) dp[i][j] += dp[i - 1][k];
			dp[i][j] %=  mod;
		}
	for (int i = 0; i < 10; i++) sum += dp[n][i];
	printf("%d", sum % mod);
	return 0;
}