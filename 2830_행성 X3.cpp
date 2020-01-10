#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
long long n, sum,one,zero,Min=20;
int arr[1000001][21];
int main()
{
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
	{
		int a;
		scanf("%d", &a);
		int j = 20;
		while (a > 0)
			arr[i][j] = a % 2, a /= 2, j--;
		if (Min > j+1) Min = j+1;
	}
	for (int k = Min; k <= 20; k++)
	{
		one = 0, zero = 0;
		int c = 20-k;
		long long b = 1;
		while (c > 0)
			b *= 2, c--;
		for (int i = 1; i <= n; i++)
		{
			if (arr[i][k] == 1)
				one++;
			else
				zero++;
		}
		if (one == n || zero == n)
			continue;
		else
			sum += one * zero * b;
	}
	printf("%lld", sum);
	return 0;
}