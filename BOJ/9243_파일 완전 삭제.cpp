#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n;
string a, b;
int main()
{
	scanf("%d", &n);
	cin >> a;
	cin >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			if (a[j] == '1')
				a[j] = '0';
			else
				a[j] = '1';
		}
	}
	if (a == b)
		printf("Deletion succeeded");
	else
		printf("Deletion failed");
	return 0;
}