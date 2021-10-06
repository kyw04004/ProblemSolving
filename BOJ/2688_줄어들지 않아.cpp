#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
ll T, n, dp[65][11], cnt;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 10; i++) dp[1][i] = 1;
	for (int i = 2; i <= 64; i++)
		for (int j = 1; j <= 10; j++) 
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
	cin >> T;
	while (T--) {
		cin >> n;
		cnt = 0;
		for (int i = 1; i <= 10; i++)
			cnt += dp[n][i];
		cout << cnt << '\n';
	}
	return 0;
}