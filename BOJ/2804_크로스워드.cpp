#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
	char ans[31][31];
	char a[31];
	char b[31];
	int ansn, ansm;
	scanf("%s%s", a, b);
	for (int i = 0; i < strlen(a); i++)
		for (int j = 0; j < strlen(b); j++)
			ans[j][i] = '.';
	for (int i = 0; i < strlen(a); i++)
	{
		for (int j = 0; j < strlen(b); j++)
			if (a[i] == b[j])
			{
				ans[j][i] = a[i];
				ansn = j;
				ansm = i;
				i = strlen(a) + 1;
			}
	}
	for (int i = 0; i < strlen(a); i++)
		ans[ansn][i] = a[i];
	for (int i = 0; i < strlen(b); i++)
		ans[i][ansm] = b[i];
	for (int i = 0; i < strlen(b); i++)
	{ 
		for (int j = 0; j < strlen(a); j++)
		{
			printf("%c", ans[i][j]);
		}
		printf("\n");
		}
	return 0;
}