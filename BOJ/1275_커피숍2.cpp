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
int n, m, h;
vector<ll> tree;
void update(int idx, ll val)
{
	idx += h;
	tree[idx] = val;
	while (idx /= 2)
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
ll query(int left, int right)
{
	ll ret = 0;
	left += h;
	right += h;
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
	scanf("%d %d", &n, &m);
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2, 0);
	for (int i = 0; i < n; i++)
	{
		ll va;
		scanf("%lld", &va);
		update(i, va);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%lld\n", query(min(a - 1,b-1), max(a-1,b-1)));
		update(c - 1, d);
	}
	return 0;
}