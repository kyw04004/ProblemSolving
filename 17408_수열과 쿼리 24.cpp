#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int h, n, m, k;
vector<pair<int,int>> tree;
int arr[100001];
void update(int idx, int val)
{
	idx += h;
	tree[idx].first = val;
	while (idx /= 2)
	{
		int a[4] = { 0 };
		a[0] = tree[idx * 2].first;
		a[1] = tree[idx * 2 + 1].first;
		a[2] = tree[idx * 2].second;
		a[3] = tree[idx * 2 + 1].second;
		sort(a, a + 4);
		tree[idx].first = a[3];
		tree[idx].second = a[2];
	}
}
int query(int left, int right)
{
	int ret = 0;
	left += h;
	right += h;
	vector<int> v;
	int i = 0;
	for (; left < right; left /= 2, right /= 2)
	{
		if (left % 2)
		{
			v.push_back(tree[left].first);
			v.push_back(tree[left++].second);
			i += 2;
		}
		if (!(right % 2))
		{
			v.push_back(tree[right].first);
			v.push_back(tree[right--].second);
			i += 2;
		}
	}
	if (left == right)
	{
		v.push_back(tree[left].first);
		v.push_back(tree[left].second);
		i += 2;
	}
	for (int j = 0; j < i; j++)
		sort(v.begin(), v.end());
	ret = v[i-2] + v[i-1];
	return ret;
}
int main()
{
	scanf(" %d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %d", &arr[i]);
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2);
	for (int i = 0; i < h * 2; i++)
		tree.push_back({ 0,0 });
	for (int i = h; i < h + n; i++)
		tree[i].first = arr[i - h];
	for (int i = h - 1; i > 0; i--)
	{
		int a[4] = {0};
		a[0] = tree[i * 2].first;
		a[1] = tree[i * 2 + 1].first;
		a[2] = tree[i * 2].second;
		a[3] = tree[i * 2 + 1].second;
		sort(a, a + 4);
		tree[i].first=a[3];
		tree[i].second = a[2];
	}
	scanf(" %d", &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf(" %d %d %d",&a,&b,&c);
		if (a == 1)
			update(b - 1, c);
		if (a == 2)
			printf("%d\n", query(b - 1, c - 1));
	}
	return 0;
}