#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int h, n, m, k, Min = 1e9, Max;
vector<pair<int, int>> tree;
int arr[100001];
void query(int left, int right)
{
	left += h;
	right += h;
	Min = 1e9, Max = 0;
	for (; left < right; left /= 2, right /= 2)
	{
		if (left % 2)
		{
			Min = min(Min, tree[left].first);
			Max = max(Max, tree[left++].second);
		}
		if (!(right % 2))
		{
			Min = min(Min, tree[right].first);
			Max = max(Max, tree[right--].second);
		}
	}
	if (left == right)
	{
		Min = min(Min, tree[left].first);
		Max = max(Max, tree[left].second);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2 + 1);
	for (int i = 0; i < h * 2 + 1; i++)
		tree.push_back({ 1e9,-1 });
	for (int i = h; i < h + n; i++)
	{
		tree[i].first = arr[i - h];
		tree[i].second = arr[i - h];
	}
	for (int i = h - 1; i > 0; i--)
	{
		tree[i].first = min(tree[i * 2].first, tree[i * 2 + 1].first);
		tree[i].second = max(tree[i * 2].second, tree[i * 2 + 1].second);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		query(a - 1, b - 1);
		printf("%d %d\n", Min, Max);
	}
	return 0;
}