#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int arr[101];
int Max;
int main()
{
	int n, sum;
	cin >> n >> sum;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = j + 1; k <= n; k++)
				if (arr[i] + arr[j] + arr[k] <= sum)
					if (Max < arr[i] + arr[j] + arr[k])
						Max = arr[i] + arr[j] + arr[k];
	printf("%d", Max);
	return 0;
}