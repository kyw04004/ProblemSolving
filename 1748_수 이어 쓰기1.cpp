#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	int n,cnt=0;
	scanf("%d", &n);
	int test = n,i=0;
	while (test > 0)
	{
		test /= 10;
		i++;
	}
	while (i > 0)
	{
		int t = 1;
		int j = i;
		while (j > 1)
		{
			t *= 10;
			j--;
		}
		cnt += i * (n - t +1);
		n = t - 1;
		i--;
	}
	printf("%d", cnt);
	return 0;
}