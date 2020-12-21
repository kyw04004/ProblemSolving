#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int h, n, m, Min = 1e9;
vector<int> tree;
void update(int idx, int val)
{
	idx += h;
	tree[idx] = val;
	while (idx /= 2)
		tree[idx] = min(tree[idx * 2] , tree[idx * 2 + 1]);
}
int query(int left, int right)
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
	return Min;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2 , 1e9);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin>>a;
		update(i, a);
	}
	for (int i = 0; i < n; i++)
		cout<<query(max(0,i-m+1) , i)<< " ";
	return 0;
}