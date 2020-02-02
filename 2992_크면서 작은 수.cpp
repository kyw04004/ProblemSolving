#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int input[7],n, i, Min=1e9;
int chk[7];
void go(int depth,int sum)
{
	if (depth == i)
	{
		if (sum<Min&&sum>n)
			Min = sum;
		return;
	}
	for (int j = 0; j < i; j++)
		if (chk[j] == 0)
		{
			chk[j] = 1;
			go(depth + 1, sum * 10 + input[j]);
			chk[j] = 0;
		}
}
int main()
{
	scanf("%d", &n);
	int nn = n;
	while (nn > 0)
	{
		input[i] = nn % 10;
		nn /= 10;
		i++;
	}
	go(0,0);
	if (Min == 1e9)
		printf("0");
	else
		printf("%d", Min);
	return 0;
}
