#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int h, n,m;
vector<int> tree;
void update(int idx, int val)
{
	idx += h - 1;
	tree[idx] += val;
	while (idx /= 2)
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}
int nquery(int node, int val)
{
	if(tree[node]>val&&node*2>=h*2)
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
int main()
{
	n = 1000000;
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2, 0);
	scanf(" %d", &m);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		scanf(" %d", &a);
		if (a == 1)
		{
			scanf(" %d", &b);
			int nn = nquery(1, b);
			printf("%d\n",nn);
			update(nn, -1);
		}
		if (a == 2)
		{
			scanf(" %d %d", &b, &c);
			update(b, c);
		}
	}
	return 0;
}