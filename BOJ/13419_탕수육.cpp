#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int n;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		int len = str.size();
		if (len % 2 == 0)
		{
			for (int i = 0; i < len; i += 2)
				printf("%c", str[i]);
			printf("\n");
			for (int i = 1; i < len; i += 2)
				printf("%c", str[i]);
			printf("\n");
		}
		else
		{
			for (int i = 0; i < len; i += 2)
				printf("%c", str[i]);
			for (int i = 1; i < len; i += 2)
				printf("%c", str[i]);
			printf("\n");
			for (int i = 1; i < len; i += 2)
				printf("%c", str[i]);
			for (int i = 0; i < len; i += 2)
				printf("%c", str[i]);
			printf("\n");
		}
	}
	return 0;
}