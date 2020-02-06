#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll h, n, m;
vector<ll> tree;
void update(int idx, ll val)
{
	idx += h;
	tree[idx] = val;
	while (idx /= 2)
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
ll query(ll left, ll right)
{
	left += h;
	right += h;
	ll ret = 0;
	for (; left < right; left /= 2, right /= 2)
	{
		if (left % 2)
			ret += tree[left++];
		if (!(right % 2))
			ret += tree[right--];
	}
	if (left == right)
		ret += tree[left];
	return ret;
}
int main()
{
	cin >> n >> m;
	h = (1 << (ll)log2(n - 1) + 1);
	tree.resize(h * 2, 0);
	for (ll i = 0; i < m; i++)
	{
		ll a,b,c;
		scanf("%lld", &a);
		if (a == 0)
		{
			scanf("%lld %lld", &b, &c);
			printf("%lld\n", query(min(c-1,b-1), max(c - 1, b - 1)));
		}
		if (a == 1)
		{
			scanf("%lld %lld", &b, &c);
			update(b-1,c);
		}
	}
	return 0;
}