#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int n, m, dp[105][105], Min = 1e9, Mini,Minj;
vector<int> v[105];
void dfs(int st, int now) {
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (dp[st][now] + 1 < dp[st][next]) {
			dp[st][next] = min(dp[st][next], dp[st][now] + 1);
			dfs(st, next);
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] = 1e9;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
		dfs(i, i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			int sum = 0;
			for (int k = 1; k <= n; k++) 
				sum += min(dp[i][k], dp[j][k]);
			if (Min > sum) Min = sum, Mini = i, Minj = j;
		}
	}
	cout << Mini << ' ' << Minj << ' ' << 2 * Min;
	return 0;
}