#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int n,Max=0;
	int temp = 0;
	int a[100001];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	/* 
	for(int i=0;i<n;i++) //시간초과
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		*/
	sort(a, a+n);
	Max = a[n - 1];
	for (int i = n-2; i >=0; i--)
	{
		Max = max(Max-1, a[i]);
	}
	printf("%d", Max+n+1);
	return 0;
}