#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int h, n, m, Max;
vector<int> tree;
int arr[1000002];
void query(int left, int right)
{
	left += h;
	right += h;
	Max = 0;
	for (; left < right; left /= 2, right /= 2)
	{
		if (left % 2)
			Max = max(Max, tree[left++]);
		if (!(right % 2))
			Max = max(Max, tree[right--]);
	}
	if (left == right)
		Max = max(Max, tree[left]);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2 + 1, 0);
	for (int i = h; i < h + n; i++)
		tree[i] = arr[i - h];
	for (int i = h - 1; i > 0; i--)
		tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
	for (int i = m - 1; i <= n - m; i++)
	{
		query(i - m + 1, i + m - 1);
		printf("%d ", Max);
	}
	return 0;
}