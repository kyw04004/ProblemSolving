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
int n, dp[100001], chk[100001];
int c1, c2;
vector<pair<int, int>> v[100001];
void dfs(int now) {
	chk[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i].first;
		if (!chk[next]) {
			dp[next] += (dp[now] + v[now][i].second);
			dfs(next);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1);
	int Max = -1;
	int Maxs = -1;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > Max) {
			Max = dp[i];
			Maxs = i;
		}
	}
	memset(chk, 0, sizeof(chk));
	memset(dp, 0, sizeof(dp));
	dfs(Maxs);
	Max = -1;
	int Maxe = -1;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > Max) {
			Max = dp[i];
			Maxe = i;
		}
	}
	memset(chk, 0, sizeof(chk));
	memset(dp, 0, sizeof(dp));
	chk[Maxe] = 1;
	dfs(Maxs);
	sort(dp + 1, dp + n + 1);
	c1 = dp[n];
	memset(chk, 0, sizeof(chk));
	memset(dp, 0, sizeof(dp));
	chk[Maxs] = 1;
	dfs(Maxe);
	sort(dp + 1, dp + n + 1);
	c2 = dp[n];
	cout << max(c1, c2);
	return 0;
}