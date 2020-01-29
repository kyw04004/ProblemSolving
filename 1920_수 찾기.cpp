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
int n, m;
int com[100001];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &com[i]);
	sort(com, com + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a;
		scanf("%d", &a);
		int left = 0, right = n-1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			if (a > com[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		if (com[left] == a)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}