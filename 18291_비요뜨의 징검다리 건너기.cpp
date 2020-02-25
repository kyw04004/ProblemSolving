#include<stdio.h>
typedef long long ll;
ll t,n;
ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	ll val = power(x, y / 2);
	if(y%2==1)
		return (x * val * val)%1000000007;
	if(y%2==0)
		return (val * val)%1000000007;
}
int main()
{
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld", &n);
		if (n <= 2)
			printf("1\n");
		else
			printf("%lld\n", power(2, n - 2)%1000000007);
	}
	return 0;
}
