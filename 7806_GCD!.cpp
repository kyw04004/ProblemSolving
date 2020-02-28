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
ll n, k, sum, j, km, nm;
ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	ll val = power(x, y / 2);
	if (y % 2 == 1)
		return (x * val * val);
	if (y % 2 == 0)
		return (val * val);
}
int main()
{
	while (scanf("%lld %lld", &n, &k) != EOF)
	{
		sum = 1, j = k;
		for (ll i = 2; i*i <= j; i++)
		{
			if (k <= 1 || k < i || n == 0)
				break;
			km = 0, nm = 0;
			while (k % i == 0) 
			{
				k /= i;
				km++;
			}
			for (ll j = i; j <= n; j *= i)  
				nm += n / j;
			sum *= power(i, min(km, nm));
		}
		if (k <= n)
			sum *= k;
		printf("%lld\n", sum);
	}
	return 0;
}
