#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int n,sum, arr[50001],ans, Max;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		ans = sum;
		for (int j = i + 1; j <= n; j++)
		{
			ans -= arr[j];
			Max = max(Max,min(ans, sum-ans));
		}
	}
	printf("%d", Max);
	return 0;
}