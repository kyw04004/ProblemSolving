#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, L, R, dp[101][101][101];
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> L >> R;
	dp[1][1][1] = 1;
	for (ll h = 2; h <= N; h++)
		for (ll l = 1; l <= L; l++)
			for (ll r = 1; r <= R; r++)
				dp[h][l][r] = (dp[h - 1][l][r] * (h - 2) + dp[h - 1][l - 1][r] + dp[h - 1][l][r - 1]) % 1000000007;
	cout << dp[N][L][R];
	return 0;
}