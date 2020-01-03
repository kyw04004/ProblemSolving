#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int L, n, Max1,Max2,ans1,ans2;
int arr[1001];
int M[1001];
int main()
{
	cin >> L >> n;
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		scanf(" %d %d", &a, &b);
		if (Max1 < b - a + 1)
		{
			Max1 = b-a+1;
			ans1 = i;
		}
		for (int j = a; j <= b; j++)
			if (arr[j] == 0)
				arr[j] = i;
	}
	for (int i = 1; i <= L; i++)
	{
		if (arr[i] != 0)
			M[arr[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (M[i] > Max2)
		{
			Max2 = M[i];
			ans2 = i;
		}
	}
	printf("%d\n", ans1);
	printf("%d\n", ans2);
	return 0;
}