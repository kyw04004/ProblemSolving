#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int arr[2200][2200];
int m, z, p;
void go(int n, int x,int y)
{
	int s = arr[x][y];
	for(int i=x;i<x+n;i++)
		for (int j = y; j < y + n; j++)
		{
			if (arr[i][j] != s)
			{
				go(n / 3, x, y);
				go(n / 3, x, y + n / 3);
				go(n / 3, x, y + 2*n / 3);
				go(n / 3, x + n / 3, y);
				go(n / 3, x + 2*n / 3, y);
				go(n / 3, x + n / 3, y + n / 3);
				go(n / 3, x + n / 3, y + 2*n / 3);
				go(n / 3, x + 2*n / 3, y + n / 3);
				go(n / 3, x + 2 * n / 3, y + 2*n / 3);
				return;
			}
		}
	if (s == -1)
		m++;
	if (s == 0)
		z++;
	if (s == 1)
		p++;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	go(n, 1,1);
	printf("%d\n%d\n%d\n", m, z, p);
	return 0;
}