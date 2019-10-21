#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n, Max, sum, i = 1;
int arr[100001];
int dp[100001];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	dp[1] = arr[1];
	dp[2] = max(arr[1] + arr[2], arr[1]);
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	for (int i = 4; i <= n; i++)
		dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 2] + arr[i]);
	printf("%d", dp[n]);
	return 0;
}