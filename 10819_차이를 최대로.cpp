#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int n, Max = -1e3;
int arr[9];
int ans[9];
int chk[9];
void go(int cnt)
{
	if (cnt == n)
	{
		int sum = 0;
		for (int i = 1; i < n; i++)
			sum += abs(ans[i - 1] - ans[i]);
		if (Max < sum)
			Max = sum;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (chk[i] == 0)
		{
			chk[i] = 1;
			ans[cnt] = arr[i];
			go(cnt + 1);
			ans[cnt] = 0;
			chk[i] = 0;
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	go(0);
	printf("%d", Max);
	return 0;
}