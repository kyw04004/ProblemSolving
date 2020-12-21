#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<functional>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
ll val[101][101],dp[101][101],n,cnt;
ll go(int x, int y)
{
	if (x > n || y > n) return 0;
	if (x == n && y == n) return 1;
	ll& ret = dp[x][y];
	if (ret != -1) return dp[x][y];
	ret = 0;
	ret += go(x, y + val[x][y]);
	ret += go(x + val[x][y], y );
	return ret;
}
int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &val[i][j]);
	printf("%lld", go(1, 1));
	return 0;
}