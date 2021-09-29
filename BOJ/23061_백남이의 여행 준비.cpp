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
int n, k, w[102], v[102], m, num = 1, dp[105][1000005];
p bag[105];
double ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for (int i = 0; i < m; i++) {
		cin >> bag[i].first;
		bag[i].second = i + 1;
	}
	sort(bag, bag + m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= bag[m - 1].first; j++) {
			if (j >= w[i])dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - w[i]]) + v[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	for (int i = 0; i < m; i++) {
		double a = (double)dp[n][bag[i].first] / (double)bag[i].first;
		if (ans < a) {
			ans = a;
			num = bag[i].second;
		}
	}
	cout << num;
	return 0;
}