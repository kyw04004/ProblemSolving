#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int arr[1025][1025], dp[1025][1025];
int main() {
	int n, m,t;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + arr[i][j] - dp[i - 1][j - 1];
		}
	cin >> t;
	while (t--)
	{
		int a, b, c, d,x,y,ans;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		ans = dp[c][d] - (dp[a - 1][d] + dp[c][b - 1] - dp[a - 1][b - 1]);
		printf("%d\n", ans);
	}
	return 0;
}