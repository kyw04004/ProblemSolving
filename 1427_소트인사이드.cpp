#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n,a[10],i=0,temp;
	cin >> n;
	while (n > 0)
	{
		a[i] = n % 10;
		n = n / 10;
		i++;
	}
	for(int j=0;j<i;j++)
		for (int k = j + 1; k < i; k++)
		{
			if (a[j] < a[k])
			{
				temp = a[j];
				a[j] = a[k];
				a[k] = temp;
			}
		}
	for (int j = 0; j < i; j++)
		printf("%d", a[j]);
	return 0;
}