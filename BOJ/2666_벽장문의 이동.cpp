#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int cnt, N, open1, open2, dp[21][21][21], order[21];
int go(int idx, int one, int two) {
	if (idx > N) return 0;
	int& ret = dp[idx][one][two];
	if (ret != -1) return ret;
	ret = min(go(idx+1,order[idx], two) + abs(one-order[idx]), go(idx+1,one, order[idx]) + abs(two-order[idx]));
	return ret;
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	memset(dp, -1, sizeof(dp));
	cin >> cnt;
	cin >> open1 >> open2;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> order[i];
	cout << go(1, open1, open2);
	return 0;
}