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
int T, N, M, won[21], dp[10005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; i++) cin >> won[i];
		cin >> M;
		dp[0] = 1;
		for (int i = 0; i < N; i++)
			for (int j = 1; j <= M; j++)
				if(j >= won[i]) dp[j] += dp[j - won[i]];
		cout << dp[M] << '\n';
	}
	return 0;
}