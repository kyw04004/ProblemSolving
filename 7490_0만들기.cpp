#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int t, n;
char arr[22];
void go(int depth)
{
	if (depth == n)
	{
		int sum = 0;
		int a = 1;
		for (int i = 2; i <= n; i++)
		{
			if (arr[i] == ' ')
			{
				if (a >= 0)
					a = 10 * a + i;
				else
					a = 10 * a - i;
			}
			if (arr[i] == '+')
			{
				sum += a;
				a = i;
			}
			if (arr[i] == '-')
			{
				sum += a;
				a = -i;
			}
		}
		sum += a;
		if (sum == 0)
		{
			printf("1");
			for (int i = 2; i <= n; i++)
				printf("%c%d", arr[i], i);
			printf("\n");
		}
		return;
	}
	arr[depth + 1] = ' ';
	go(depth + 1);
	arr[depth + 1] = '+';
	go(depth + 1);
	arr[depth + 1] = '-';
	go(depth + 1);
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		go(1);
		printf("\n");
	}
	return 0;
}
