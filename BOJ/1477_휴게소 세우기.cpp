#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
int n, m, L, arr[105];
int main()
{
	scanf("%d %d %d", &n, &m, &L);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	arr[n] = 0, arr[n + 1] = L;
	sort(arr, arr + n + 2);
	int left = 0, right = L;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int t = 0;
		for (int i = 1; i < n + 2; i++)
			t += (arr[i] - arr[i - 1] - 1) / mid;
		if (m < t)
			left = mid + 1;
		else
			right = mid - 1;
	}
	printf("%d", left);
	return 0;
}
