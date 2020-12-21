#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int n, a[1000001], b, c;
long long cnt;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	scanf("%d %d", &b, &c);
	cnt += n;
	for (int i = 0; i < n; i++)
	{
		a[i] -= (1 + b);
		if (a[i] >= 0)
			cnt += (a[i] / c) + 1;
	}
	printf("%lld", cnt);
	return 0;
}