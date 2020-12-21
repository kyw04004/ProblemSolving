#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
int a[10005],cnt;
int main()
{
	int n,s;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&s);
		a[s]++;
	}
	for (int i = 1; i <= 10000; i++)
		if(a[i]!=0)
			for (int j = 0; j < a[i]; j++)
			{
				cnt++;
				printf("%d\n", i);
				if (cnt == n)
					return 0;
			}
	return 0;
}