#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll N, M, K, S, T, dp[11][100005];
vector<pair<pair<ll,ll>, ll>> v;
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K >> S >> T;
	for (int i = 0; i < M; i++) {
		ll a, b, c; cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}
	sort(v.begin(), v.end());
	dp[0][S] = 0;
	for (int i = 0; i <= K; i++) {
		if (i >= 1)
			for (int j = 0; j < v.size(); j++) {
				ll now = v[j].first.first;
				ll next = v[j].first.second;
				dp[i][now] = max(dp[i][now], dp[i - 1][next]);
			}
		for (int j = 0; j < v.size(); j++) {
			ll now = v[j].first.first;
			ll next = v[j].first.second;
			ll cost = v[j].second;
			if (dp[i][now] == -1) continue;
			dp[i][next] = max(dp[i][next], dp[i][now] + cost);
		}
	}
	cout << dp[K][T];
	return 0;
}