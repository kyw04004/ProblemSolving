#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	int n, m,compare,Max=0;
	int arr[51][51] = { 0 };
	scanf(" %d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &arr[i][j]);
	for(int k=0;k<min(n,m);k++)
		for (int i = 1; i <= n-k; i++)
			for (int j = 1; j <= m-k; j++)
			{
				if (arr[i][j] == arr[i + k][j] && arr[i + k][j] == arr[i][j + k] && arr[i][j + k] == arr[i + k][j + k])
				{
					compare = (k+1)*(k+1);
					if (compare > Max)
						Max = compare;
				}
			}
	printf("%d", Max);
	return 0;
}