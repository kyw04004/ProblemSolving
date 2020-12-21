#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int dp[12];
int t, n;
int main()
{
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i < 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}