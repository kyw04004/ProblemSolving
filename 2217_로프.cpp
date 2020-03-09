#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, arr[100001], Max;
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = n - 1; i >= 0; i--)
	{
		int com = arr[i] * (n - i);
		if (com > Max)
			Max = com;
	}
	printf("%d", Max);
	return 0;
}
