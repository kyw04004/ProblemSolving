#include<stdio.h>
int t, n, dp[1001];
int main()
{
	for (int i = 1; i <= 1000; i++)
		dp[i] = 1;
	for (int i = 2; i <= 1000; i++)
		for (int j = 0; j <= i; j++)
			if ((i - j) % 2 == 0)
				dp[i] += dp[(i - j) / 2];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}