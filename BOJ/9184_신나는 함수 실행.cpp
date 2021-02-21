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
int dp[55][55][55];
int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	int &ret = dp[a][b][c];
	if (ret != -1) return ret;
	ret = 0;
	if (a < b && b < c)
		ret = (w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c));
	else
		ret = (w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b , c - 1) - w(a - 1, b - 1, c - 1));
	return ret;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n",a,b,c, w(a, b, c));
	}
	return 0;
}