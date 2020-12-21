#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
int arr[10001],Max;
int main()
{
	int n, sum;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (Max < arr[i])
			Max = arr[i];
	}
	scanf("%d", &sum);
	int left = 0, right = Max, ans;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] < mid)
				sum2 += arr[i];
			else
				sum2 += mid;
		}
		if (sum < sum2)
			right = mid - 1;
		else
			left = mid + 1;
	}
	printf("%d", right);
	return 0;
}