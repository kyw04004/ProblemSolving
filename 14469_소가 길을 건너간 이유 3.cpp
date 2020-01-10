#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
pair<int, int> arr[101];
int main()
{
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i].first);
		scanf("%d", &arr[i].second);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		if (sum >= arr[i].first)
			sum -= arr[i].first;
		else
			arr[i].first -= sum;
		sum += (arr[i].first + arr[i].second);
	}
	printf("%d", sum);
	return 0;
}