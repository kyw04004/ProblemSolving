#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int n,dp[1000001],chk;
int go(int n) {
	if (n == 1) return 0;
	int &ret = dp[n];
	if (ret != -1) return ret;
	ret = 1e9;
	if (n % 3 == 0) ret = min(ret, go(n / 3) + 1);
	if (n % 2 == 0) ret = min(ret, go(n / 2) + 1);
	if (n - 1 >= 1) ret = min(ret, go(n - 1) + 1);
	return ret;
}
int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(n));
	printf("%d ", n);
	dp[1] = 0;
	while (n != 1) {
		if (n % 3 == 0 && dp[n / 3] + 1 == dp[n]) {
			n /= 3;
			printf("%d ", n);
			continue;
		}
		if (n % 2 == 0 && dp[n / 2] + 1 == dp[n]) {
			n /= 2;
			printf("%d ", n);
			continue;
		}
		if ((n - 1) >= 1 && dp[n - 1] + 1 == dp[n]) {
			n -= 1;
			printf("%d ", n);
			continue;
		}
	}
	return 0;
}