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
map <ll, int> m;
ll n,arr[101],ans[101],chk;
void go(ll now, int depth)
{
	if (m[now] != 1)
		return;
	if (depth == n && chk == 0)
	{
		chk = 1;
		for (int i = 1; i <= n; i++)
			printf("%lld ", ans[i]);
		printf("\n");
		return;
	}

	if (ans[depth] % 3 == 0)
	{
		ans[depth + 1] = now / 3;
		go(now / 3, depth + 1);
	}
	ans[depth + 1] = now * 2;
	go(now * 2, depth + 1);
}
int main()
{
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr[i]);
		m[arr[i]] = 1;
	}
	for(int i=0;i<n;i++)
		if (chk == 0)
		{
			ans[1] = arr[i];
			go(arr[i], 1);
		}
	return 0;
}