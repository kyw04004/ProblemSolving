#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int chk = i;
		sum = 0;
		while (chk > 0)
		{
			sum += chk % 10;
			chk /= 10;
		}
		if (i + sum == n)
		{
			printf("%d", i);
			return 0;
		}
	}
	printf("0");
	return 0;
}