#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
int n, k, dp[1001][1001];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i <= n; i++) dp[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
	cout << dp[n][k];
	return 0;
}