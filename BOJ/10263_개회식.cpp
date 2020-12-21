#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std; 
int main()
{
	int n,Min;
	int arr[100001] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	Min = n;
	for (int i = 0; i < n; i++)
		Min = min(Min, arr[i] + n - i - 1);
	printf("%d", Min);
	return 0;
}