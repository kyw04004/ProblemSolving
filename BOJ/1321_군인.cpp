#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<functional>
#include<cmath>
using namespace std;
typedef long long ll;
int n, h, m;
vector<int> tree;
void update(int idx, int val)
{
	idx += h;
	tree[idx] += val;
	while (idx /= 2)
		tree[idx] = tree[idx * 2 + 1] + tree[idx * 2];
}
int nquery(int node, int val)
{
	if (tree[node] > val && node * 2 >= h * 2)
		return node - h + 1;
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
		return node - h + 1;
	}
	if (val > tree[node * 2])
		return nquery(node * 2 + 1, val - tree[node * 2]);
	else
		return nquery(node * 2, val);
}
int main() {
	scanf("%d", &n);
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2, 0);
	for (int i = 0; i < n; i++)
	{
		int value;
		scanf("%d", &value);
		update(i, value);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf("%d", &a);
		if (a == 1)
		{
			scanf("%d %d", &b, &c);
			update(b - 1, c);
		}
		if (a == 2)
		{
			scanf("%d", &b);
			printf("%d\n", nquery(1,b));
		}
	}
	return 0;
}