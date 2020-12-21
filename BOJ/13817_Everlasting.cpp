#include<stdio.h>
#include<iostream>
using namespace std;
int a, b,Ma,Mb;
int main()
{
	while (1)
	{
		int an[1000001] = { 0, };
		int bn[1000001] = { 0, };
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		int n = 2;
		while (1)
		{
			if (a == 1) break;
			if (a%n == 0)
			{
				an[n] = 1;
				Ma = n;
				a /= n;
			}
			else
				n++;
		}
		n = 2;
		while (1)
		{
			if (b == 1) break;
			if (b%n == 0)
			{
				bn[n] = 1;
				Mb = n;
				b /= n;
			}
			else
				n++;
		}
		int j = Ma;
		for (int i = 1; i < j; i++)
			if (an[i] == 1)
				Ma -= i;
		j = Mb;
		for (int i = 1; i < j; i++)
			if (bn[i] == 1)
				Mb -= i;
		if (Ma > Mb)
			printf("a\n");
		else
			printf("b\n");
	}
	return 0;
}