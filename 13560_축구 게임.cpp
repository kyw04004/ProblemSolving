#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
int n,sum,a,guide,arr[10001];
int main() {        
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr,arr+n);
	for (int i = n-1; i >= 0; i--)
	{
		sum += arr[i];
		guide += i;
		if (sum > guide)
		{
			printf("-1");
			return 0;
		}
	}
	if (n*(n - 1)/ 2 == sum)
		printf("1");
	else
		printf("-1");
	return 0;
}

