#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int dp[1005][1005];
stack<char> s;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	int alen = a.size(), blen = b.size();
	for (int i = 1; i <= alen; i++)
		for (int j = 1; j <= blen; j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	cout << dp[alen][blen] << '\n';
	while (dp[alen][blen]) {
		if (dp[alen][blen] == dp[alen - 1][blen]) alen -= 1;
		else if (dp[alen][blen] == dp[alen][blen - 1]) blen -= 1;
		else {
			s.push(a[alen-1]);
			alen -= 1, blen -= 1;
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}