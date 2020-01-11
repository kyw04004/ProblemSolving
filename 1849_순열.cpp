#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int h, n, arr[100001], ans[100001];
vector<int> tree;
void update(int idx, int val)
{
	idx += h - 1;
	tree[idx] = val;
	while (idx /= 2)
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
int nquery(int node, int val)
{
	if (tree[node] == val)
	{
		while(node*2<h*2)
		{
			if (tree[node * 2 + 1] != 0)
			{
				node *= 2;
				node += 1;
			}
			else
				node *= 2;
		} 
		return node-h+1;
	}
	if (val > tree[node * 2])
		return nquery(node * 2+1, val-tree[node*2]);
	else
		return nquery(node * 2, val);
}
int main()
{
	scanf(" %d", &n);
	h = (1<< (int)log2(n - 1) + 1);
	tree.resize(h * 2, 0);
	for (int i = 1; i <= n;i++)
		update(i,1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		int a = nquery(1, arr[i] + 1);
		ans[a] = i;
		update(a, 0);
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}