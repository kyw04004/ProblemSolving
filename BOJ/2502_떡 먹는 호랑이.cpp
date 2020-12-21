#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
pair<int, int> dp[33];
int main() {
	int n, ans,a,b,i,j;
	scanf("%d %d", &n, &ans);
	dp[1].first = 1;
	dp[1].second = 0;
	dp[2].first = 0;
	dp[2].second = 1;
	for (int i = 3; i <= 30; i++)
	{
		dp[i].first = dp[i - 1].first + dp[i - 2].first;
		dp[i].second = dp[i - 1].second + dp[i - 2].second;
	}
	a = dp[n].first;
	b = dp[n].second;
	for (i = 1; i <= ans; i++)
		for (j = 1; j <= ans; j++)
			if (a * i + b * j == ans)
			{
				printf("%d\n", i);
				printf("%d\n", j);
				i = ans + 1;
				j = ans + 1;
			}
	return 0;
}