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
ll ans=1, n;
int main()
{
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++)
		ans *= (2 * i - 1), ans %= 1000000009;
	printf("%lld", ans);
	return 0;
}
