#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int n, ans1, ans2, ans3;
char arr[100001];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
		if (arr[i] == 'L')
			ans1 -= 1;
	for (int i = 1; i <= n; i++)
		if (arr[i] == 'R')
			ans2 += 1;
	ans3 = ans2 - ans1 + 1;
	printf("%d", ans3);
	return 0;
}