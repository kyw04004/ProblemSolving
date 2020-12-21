#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
int n,s[100001],arr[100001];
vector <int> tree;
void update(int i, int num)
{
	while (i <= n)
	{
		tree[i] += num;
		i += (i&-i);
	}
}
int query(int i)
{
	int ans = 0;
	while (i > 0)
	{
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}
int main()
{
	scanf("%d", &n);
	tree.resize(n + 2, 0);
	for (int i = 1; i <= n; i++)
		update(i, 1);
	for (int i = 1; i <= n; i++)
	{
		int input;
		scanf("%d", &input);
		s[input] = i;
	}
	for (int i = 1,j=1; j <= n; i++,j+=2)
	{
		arr[j] = s[i];
		arr[j + 1] = s[(n - i) + 1];
	}
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
			printf("%d\n", query(arr[i] - 1));
		else
			printf("%d\n", query(n)-query(arr[i]));
		update(arr[i], -1);
	}
	return 0;
}