#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int h, n, m, k;
vector<long long> tree;
int arr[1000001];
void update(int idx, long long val)
{
	idx += h;
	tree[idx] = val;
	while (idx /= 2)
		tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % 1000000007;
}
long long query(int left, int right)
{
	long long ret = 1;
	left += h;
	right += h;
	for (;left < right; left /= 2, right /= 2)
	{
		if (left % 2)
		{
			ret *= tree[left++];
			ret %= 1000000007;
		}
		if (!(right % 2))
		{
			ret *= tree[right--];
			ret %= 1000000007;
		}
	}
	if (left == right)
	{
		ret *= tree[left];
		ret %= 1000000007;
	}
	return ret;
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2 + 1);
	for (int i = 0; i < h * 2; i++)
		tree.push_back(0);
	for (int i = h; i < h + n; i++)
		tree[i] = arr[i - h];
	for (int i = h - 1; i > 0; i--)
		tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % 1000000007;
	for (int i = 0; i < m + k; i++)
	{
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		if (a == 1)
			update(b - 1, c);
		if (a == 2)
			printf("%lld\n", query(b - 1, c - 1) % 1000000007);
	}
	return 0;
}