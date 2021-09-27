#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int N, M, yard[105], dp[105][11], ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> yard[i];
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) { // 위치
		for (int j = 1; j <= M; j++) { // 시간
			// i 위치 j 시간
			if(dp[i-2][j-1] && i >= 2) dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] / 2 + yard[i]);
			if(dp[i-1][j-1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + yard[i]);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}

