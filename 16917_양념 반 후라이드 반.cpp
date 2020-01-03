#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int a, b, c, x, y,sum;
int main()
{
	scanf(" %d %d %d %d %d", &a, &b, &c, &x, &y);
	if (a + b <= 2 * c)
		sum = a * x + b * y;
	else
	{
		int Min = min(x, y);
		sum = Min * 2* c;
		x -= Min; y -= Min;
		if (x > 0)
		{
			if (a > 2 * c)
				sum += 2 * c*x;
			else
				sum += a * x;
		}
		if (y > 0)
		{
			if (b > 2 * c)
				sum += 2 * c*y;
			else
				sum += b * y;
		}
	}
	printf("%d", sum);
	return 0;
}