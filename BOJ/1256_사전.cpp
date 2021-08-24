#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
using namespace std;
typedef unsigned long long ll;
ll n, m, k, total, dp[105][105];
void makeString(string str, ll acnt, ll zcnt, ll k) {
	if (!acnt || !zcnt) {
		if(!zcnt) for (int i = 0; i < acnt; i++) str += 'a';
		if(!acnt) for (int i = 0; i < zcnt; i++) str += 'z';
		cout << str << '\n';
		return;
	}
	if (k <= dp[acnt - 1][zcnt]) makeString(str + 'a', acnt - 1, zcnt, k);
	else makeString(str + 'z', acnt, zcnt - 1, k - dp[acnt-1][zcnt]);
}
void makeTable() {
	for (int i = 0; i <= n; i++) dp[i][0] = 1;
	for (int i = 0; i <= m; i++) dp[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	makeTable();
	if (k > dp[(int)n][(int)m]) cout << "-1\n";
	else makeString("", n, m, k);
	return 0;
}

