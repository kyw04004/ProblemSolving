#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<functional>
#include<stack>
#include<vector>
using namespace std;
int val[1001][1001],dp[1001][1001];
int main()
{
	int n,m;
	cin >> n>>m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &val[i][j]);
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = val[i][j]+max(dp[i - 1][j], max(dp[i - 1][ j - 1], dp[i][j - 1]));
	printf("%d", dp[n][m]);
	return 0;
}