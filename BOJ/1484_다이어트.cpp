#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int n, chk;
int main()
{
	scanf("%d", &n);
	for (int i = sqrt(n); i <= 50000; i++) // iÃÖ´ë 50000
		for (int j = 1; j < i; j++)
		{
			if (i * i - j * j == n)
			{
				chk = 1;
				printf("%d\n", i);
			}
		}
	if (chk == 0)
		printf("-1");
	return 0;
}