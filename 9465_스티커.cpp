#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
int t,n,arr[2][100001],dp[2][100001];
int main() {
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = dp[1][0] + arr[0][1];
		dp[1][1] = dp[0][0] + arr[1][1];
		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i-1], dp[1][i-2])+arr[0][i];
			dp[1][i] = max(dp[0][i-1],dp[0][i-2])+arr[1][i];
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
	}
	return 0;
}
