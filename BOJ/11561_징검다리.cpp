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
int main()
{
	long long n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		long long a;
		scanf("%lld", &a);
		long long left, right, mid, com;
		left = 1;
		right = (long long)sqrt(a) * 2;
		while (left <= right)
		{
			mid = (left + right) / 2;
			com = mid * (mid + 1)/2;
			if (a < com)
				right = mid - 1;
			else
				left = mid + 1;
		}
		printf("%lld\n", right);
	}
	return 0;
}