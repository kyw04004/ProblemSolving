#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
int n, dp[1005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	dp[1] = dp[3] = dp[4] = 1;
	for (int i = 5; i <= 1000; i++) {
		if (dp[i - 1] && dp[i - 3] && dp[i - 4]) dp[i] = 0;
		else dp[i] = 1;
	}
	cin >> n;
	if (dp[n]) cout << "SK";
	else cout << "CY";
	return 0;
}