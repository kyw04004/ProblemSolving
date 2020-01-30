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
ll input[500001];
ll com[500001];
int main()
{
	ll n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld", &input[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &com[i]);
	for (ll i = 0; i < n; i++)
	{
		ll left = i+1, right = n - 1;
		while (left <= right)
		{
			ll mid = (left + right) / 2;
			if (com[mid] > input[i])
				right = mid - 1;
			else
				left = mid + 1;
		}
		printf("%lld ", right-i);
	}
	return 0;
}