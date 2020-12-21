#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int h, n, m, k, Min = 1e9;
vector<int> tree;
int arr[100002];
void query1(int left, int right)
{
	left += h;
	right += h;
	Min = 1e9;
	for (; left < right; left /= 2, right /= 2)
	{
		if (left % 2)
			Min = min(Min, tree[left++]);
		if (!(right % 2))
			Min = min(Min, tree[right--]);
	}
	if (left == right)
		Min = min(Min, tree[left]);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2 + 1, 1e9);
	for (int i = h; i < h + n; i++)
		tree[i] = arr[i - h];
	for (int i = h - 1; i > 0; i--)
		tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		query1(a - 1, b - 1);
		printf("%d\n", Min);
	}
	return 0;
}