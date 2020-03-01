#include<stdio.h>
int n,sum, cnt;
int main()
{
	scanf("%d", &n);
	if (n % 2 == 0 || n % 5 == 0)
		printf("-1");
	else
	{
		do
		{
			sum = (sum % n) * (10 % n) + (1 % n);
			cnt++;
		} while (sum%n != 0);
		printf("%d\n", cnt);
	}
	return 0;
}