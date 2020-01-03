#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int h, n, m, k;
vector<int> tree;
int arr[100001];
void update(int idx, int val)
{
	idx += h;
	tree[idx] = val;
	while (idx /= 2)
		tree[idx] = tree[idx * 2] * tree[idx * 2 + 1];
}
int query(int left, int right)
{
	int ret = 1;
	left += h;
	right += h;
	for (; left < right; left /= 2, right /= 2)
	{
		if (left % 2)
			ret *= tree[left++];
		if (!(right % 2))
			ret *= tree[right--];
	}
	if (left == right)
		ret *= tree[left];
	return ret;
}
int main()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		string s;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			if (arr[i] > 0)
				arr[i] = 1;
			else if (arr[i] == 0)
				arr[i] = 0;
			else
				arr[i] = -1;
		}
		h = (1 << (int)log2(n - 1) + 1);
		tree.clear();
		tree.resize(h * 2 + 1);
		for (int i = 0; i < h * 2; i++)
			tree.push_back(1);
		for (int i = h; i < h + n; i++)
			tree[i] = arr[i - h];
		for (int i = h - 1; i > 0; i--)
			tree[i] = tree[i * 2] * tree[i * 2 + 1];
		for (int i = 0; i < m; i++)
		{
			char a;
			int b, c;
			scanf(" %c %d %d", &a, &b, &c);
			if (a == 'C')
			{
				if (c > 0)
					c = 1;
				else if (c == 0)
					c = 0;
				else
					c = -1;
				update(b - 1, c);
			}
			else if (a == 'P')
			{
				int p = query(b - 1, c - 1);
				if (p > 0)
					s += "+";
				else if (p == 0)
					s += "0";
				else
					s += "-";
			}
		}
		cout << s<<"\n";
	}
	return 0;
}