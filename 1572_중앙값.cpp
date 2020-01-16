#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
long long h, n, m;
long long sum;
long long a[250001];
vector<long long> tree;
void update(long long idx, long long val)
{
	idx += h;
	tree[idx] += val;
	while (idx /= 2)
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
long long nquery(long long node, long long val)
{
	if (tree[node] > val&&node * 2 >= h * 2)
		return node - h;
	if (tree[node] == val)
	{
		while (node * 2 < h * 2)
		{
			if (tree[node * 2 + 1] != 0)
			{
				node *= 2;
				node += 1;
			}
			else
				node *= 2;
		}
		return node - h;
	}
	if (val > tree[node * 2])
		return nquery(node * 2 + 1, val - tree[node * 2]);
	else
		return nquery(node * 2, val);
}
int main()
{
	scanf(" %lld %lld", &n, &m);
	h = (1 << (long long)log2(66000 - 1) + 1);
	tree.resize(h * 2, 0);
	for (long long i = 0; i < n; i++)
	{
		scanf(" %lld", &a[i]);
		update(a[i], 1);
		if (i >= m - 1)
		{
			if (tree[a[i - m] + h] >= 1 && i >= m)
				update(a[i - m], -1);
			if (m % 2 == 0)
				sum += nquery(1, m / 2);
			else
				sum += nquery(1, m / 2 + 1);
		}
	}
	printf("%lld", sum);
	return 0;
}