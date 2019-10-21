#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dp[1000001];
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	printf("%d", dp[n]);
	return 0;
}