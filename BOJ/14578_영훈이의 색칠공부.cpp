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
int main()
{
	ll N, n,n1,n2,a,b,c;
	scanf("%lld", &N);
	if (N == 1)
	{
		printf("0\n");
		return 0;
	}
	if (N == 2)
	{
		printf("2\n");
		return 0;
	}
	if (N == 3)
	{
		printf("12\n");
		return 0;
	}
	n = 2, n1 = 1, n2 = 0;
	for (ll i = 4; i <= N; i++)
	{
		a = n, b = n1, c = n2;
		n = (i - 1) * (a + b) % 1000000007;
		n2 = b , n1 = a;
	}
	for (ll i = 2; i <= N; i++)
	{
		n *= i;
		n %= 1000000007;
	}
	printf("%lld", n % 1000000007);
	return 0;
}
