#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n, money, coin, arr[17];
int main()
{
	scanf("%lld %lld", &n, &money);
	for(ll i=1;i<=n;i++)
		scanf("%d", &arr[i]);
	for (ll i = 1; i < n; i++)
		if (arr[i] < arr[i + 1])
			coin = money / arr[i], money += coin * (arr[i+1]-arr[i]);
	printf("%lld", money);
	return 0;
}
