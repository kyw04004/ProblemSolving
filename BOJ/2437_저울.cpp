#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
int n, sum, arr[1001];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	sum = 1;
	for (int i = 0; i < n; i++) {
		if (sum < arr[i])
			break;
		sum += arr[i];
	}
	printf("%d\n", sum);
	return 0;
}