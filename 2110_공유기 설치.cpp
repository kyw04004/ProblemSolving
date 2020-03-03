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
int n,k,arr[200001];
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int left = 0, right = 1e9;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int last=0, t = 1;
		for (int i = 1; i < n; i++)
			if (arr[i] - arr[last] >= mid)
				last = i, t++;
		if (k > t)
			right = mid - 1;
		else
			left = mid + 1;
	}
	printf("%d", right);
	return 0;
}