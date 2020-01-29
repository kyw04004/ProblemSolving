#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
int com[500001];
int ans[20000001];
int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &com[i]);
		ans[com[i]+10000000]++;
	}
	sort(com, com + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		int left = 0, right = n - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (a > com[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		if (com[left] == a)
		{
			printf("%d ",ans[com[left]+10000000]);
		}
		else
			printf("0 ");
	}
	return 0;
}