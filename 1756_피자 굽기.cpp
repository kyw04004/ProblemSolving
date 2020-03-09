#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int n, m, depth[300001],dow[300001];
int main()
{
	scanf("%d %d", &n, &m);
	depth[0] = 1e9;
	for (int i = 1; i <= n; i++)
	{
		int wid;
		scanf("%d", &wid);
		depth[i] = min(wid, depth[i - 1]);
	}
	for (int j = 1; j <= m; j++)
		scanf("%d", &dow[j]);
	for (int j = 1, i = n; i >= 1; i--)
	{
		if (dow[j] <= depth[i])
		  j++;
		if (j > m)
		{
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
	return 0;
}
