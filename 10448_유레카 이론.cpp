#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int n,m, ok,arr[47];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < 46; i++)
		arr[i] = i * (i + 1) / 2;
	while (n--)
	{
		ok = 0;
		scanf("%d", &m);
		for(int i=1;i<=45;i++)
			for(int j=1;j<=45;j++)
				for(int k=1;k<=45;k++)
					if (arr[i] + arr[j] + arr[k] == m)
						ok = 1,i=46,j = 46,k = 46;
		if (ok == 1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}