#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int n, m, x, y;
char arr[101][101];
int main()
{
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n * x; i++)
		for (int j = 0; j < m * y; j++)
			arr[i][j] = '.';
	for (int i = 0; i < x*n; i++)
		for (int j = 0; j < y*m; j++)
		{
			if ((i / x) % 2 == 0 && (j / y) % 2 == 0)
				arr[i][j] = 'X';
			if ((i / x) % 2 == 1 && (j / y) % 2 == 1)
				arr[i][j] = 'X';
		}
	for (int i = 0; i < n * x; i++)
	{
		for (int j = 0; j < m * y; j++)
			printf("%c", arr[i][j]);
		printf("\n");
	}
	return 0;
}