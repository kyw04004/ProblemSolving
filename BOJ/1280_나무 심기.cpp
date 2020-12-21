#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll n, m, Max,sum = 1;
vector<ll> index_tree;
vector<ll> cnt_tree;
void index_update(ll i, ll num)
{
	while (i <= n)
	{
		index_tree[i] += num;
		i += (i & -i);
	}
}
void cnt_update(ll i, ll num)
{
	while (i <= n)
	{
		cnt_tree[i] += num;
		i += (i & -i);
	}
}
ll index_query(ll i)
{
	ll ans = 0;
	while (i > 0)
	{
		ans += index_tree[i];
		i -= (i & -i);
	}
	return ans;
}
ll cnt_query(ll i)
{
	ll ans = 0;
	while (i > 0)
	{
		ans += cnt_tree[i];
		i -= (i & -i);
	}
	return ans;
}
int main()
{
	n = 200000;
	scanf(" %lld", &m);
	index_tree.resize(n + 2, 0);
	cnt_tree.resize(n + 2, 0);
	for (int i = 0; i < m; i++)
	{
		ll x;
		scanf(" %lld", &x);
		x++;
		if (i >= 1)
		{
			ll s = 0;
			s = (s+cnt_query(x-1)*x-index_query(x-1))%1000000007;
			s = (s+(index_query(Max)-index_query(x))-(cnt_query(Max)-cnt_query(x))*x)%1000000007;
			sum = (sum*s)%1000000007;
		}
		index_update(x, x);
		cnt_update(x, 1);
		Max = max(Max, x);
	}
	printf("%lld", sum % 1000000007);
	return 0;
}