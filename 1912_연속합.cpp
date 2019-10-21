#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n, Max, sum;
int arr[100001];
int dp[100001];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	Max = dp[1] = arr[1];
	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		Max = max(Max, dp[i]);
	}
	printf("%d", Max);
	return 0;
}