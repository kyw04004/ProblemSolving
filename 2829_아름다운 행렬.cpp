#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, Max = 0;
int input[402][402];
int output1[402][402];
int output2[402][402];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> input[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			output1[i][j] = input[i][j];
			output2[i][j] = input[i][j];
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			output1[i + 1][j + 1] += output1[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = n; j >= 1; j--)
			output2[i + 1][j - 1] += output2[i][j];
	for(int i=1;i<=n;i++)
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (i + k > n || j + k > n) break;
				else
				{
					int m = (output1[i + k][j + k] - output1[i - 1][j - 1]) - (output2[i + k][j] - output2[i - 1][j + k + 1]);
					if (m > Max)
						Max = m;
				}
			}
		}
	printf("%d", Max);
	return 0;
}