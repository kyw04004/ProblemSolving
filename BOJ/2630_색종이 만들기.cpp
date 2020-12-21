#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int arr[129][129];
int z, o;
void go(int n, int x, int y)
{
	int s = arr[x][y];
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
		{
			if (arr[i][j] != s)
			{
				go(n / 2, x, y);
				go(n / 2, x, y + n / 2);
				go(n / 2, x + n / 2, y);
				go(n / 2, x + n / 2, y + n / 2);
				return;
			}
		}
	if (!s)
		z++;
	else
		o++;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	go(n, 1, 1);
	printf("%d\n%d\n", z, o);
	return 0;
}