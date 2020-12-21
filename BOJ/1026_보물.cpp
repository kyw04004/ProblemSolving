#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int n, a[51], b[51], temp, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (b[i] > b[j])
			{
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
	for (int i = 1; i <= n; i++)
		sum += a[i] * b[i];
	printf("%d", sum);
	return 0;
}