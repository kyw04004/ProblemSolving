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
long long arr[10001],M;
int main()
{
	long long n,k;
	scanf("%lld %lld", &n,&k);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
		if (M < arr[i])
			M = arr[i];
	}
	long long left = 1, right = M;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt=0;
		for (int i = 0; i < n; i++)
			cnt += arr[i] / mid;
		if (cnt < k)
			right = mid - 1;
		else
			left = mid + 1;
	}
	printf("%lld", right);
	return 0;
}