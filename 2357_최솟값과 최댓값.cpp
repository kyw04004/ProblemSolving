#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int h,n,m,k,Min=1e9,Max;
vector<int> tree1;
vector<int> tree2;
int arr[100001];
void query1(int left, int right)
{
	left += h;
	right += h;
	Min = 1e9;
	for (;left < right; left /= 2, right /= 2)
	{
		if (left % 2)
			Min = min(Min, tree1[left++]);
		if (!(right % 2))
			Min = min(Min, tree1[right--]);
	}
	if (left == right)
		Min = min(Min, tree1[left]);
}
void query2(int left, int right)
{
	left += h;
	right += h;
	Max = 0;
	for (; left < right; left /= 2, right /= 2)
	{
		if (left % 2)
			Max = max(Max, tree2[left++]);
		if (!(right % 2))
			Max = max(Max, tree2[right--]);
	}
	if (left == right)
		Max = max(Max, tree2[left]);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	h = (1 << (int)log2(n - 1) + 1);
	tree1.resize(h * 2 + 1);
	tree2.resize(h * 2 + 1);
	for (int i = 0; i < h * 2 + 1; i++)
	{
		tree1.push_back(1e9);
		tree2.push_back(0);
	}
	for (int i = h; i < h + n; i++)
	{
		tree1[i] = arr[i - h];
		tree2[i]= arr[i - h];
	}
	for (int i = h - 1; i > 0; i--)
	{
		tree1[i] = min(tree1[i * 2], tree1[i * 2 + 1]);
		tree2[i] = max(tree2[i * 2], tree2[i * 2 + 1]);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		query1(a-1, b-1);
		query2(a - 1, b - 1);
		printf("%d %d\n", Min, Max);
	}
	return 0;
}