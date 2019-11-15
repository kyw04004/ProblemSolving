#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	int n, sum = 0, i = 1;
	cin >> n;
	while (1)
	{
		sum += i;
		if (n <= sum)
			break;
		i++;
	}
	if (i % 2 == 0)
	{
		int c = 1;
		int p = i;
		int s = n - (sum - i + 1);
		for (int i = 1; i <= s; i++)
		{
			c++;
			p--;
		}
		printf("%d/%d", c, p);
	}
	else
	{
		int c = i;
		int p = 1;
		int s = n - (sum - i + 1);
		for (int i = 1; i <= s; i++)
		{
			c--;
			p++;
		}
		printf("%d/%d", c, p);
	}
	return 0;
}