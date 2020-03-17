#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int t, n, sum, cnt,two,five;
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		cnt = 0;
		sum = 0;
		two = 0;
		five = 0;
		scanf("%d", &n);
		while (n % 2 == 0)
			n /= 2, two++;
		while (n % 5 == 0)
			n /= 5, five++;
		do
		{
			sum = (sum % n) * (10 % n) + (1 % n);
			cnt++;
		} while (sum%n != 0);
		for (int i = 1; i <= cnt; i++)
			printf("1");
		for (int i = 1; i <= max(two, five); i++)
			printf("0");
		printf("\n");
	}
	return 0;
}