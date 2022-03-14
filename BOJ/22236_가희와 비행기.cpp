#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
#include<unordered_set>
using namespace std;
typedef long long ll;
ll d, m, dp[4001][2001];
ll go(int len, int h) {
	if (len == d) {
		if (h == 0) return 1;
		return 0;
	}
	if (0 < len && h <= 0) return 0;
	ll& ret = dp[len][h];
	if (ret != -1) return ret;
	ret = 0;
	if(h + 1 <=  d / 2) ret += go(len + 1, h + 1) % m;
	ret += go(len + 1, h - 1) % m;
	return ret % m;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> d >> m;
	cout << go(0, 0);
	return 0;
}