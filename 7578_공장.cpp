#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int h, n;
long long cnt;
vector<long long> tree;
int arr1[500001];
int arr2[500001];
int arr3[1000001];
void update(int idx, int val)
{
	idx += h - 1;
	tree[idx] = val;
	while (idx /= 2)
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
long long query(int left, int right)
{
	long long ret = 0;
	left += h - 1;
	right += h - 1;
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
	scanf("%d",&n);
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2,0);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr1[i]);
		arr3[arr1[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr2[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		cnt += query(arr3[arr2[i]], n);
		update(arr3[arr2[i]], 1);
	}
	printf("%lld", cnt);
	return 0;
}