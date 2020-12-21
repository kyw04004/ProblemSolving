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
typedef long long ll;
ll pa[1000001];
int main() {
	ll n, m, left, right, mid, sum=0, cnt;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &pa[i]);
		sum += pa[i];
	}
	sort(pa, pa + n);
	left = 1;
	right = pa[n-1];
	while (left <= right)
	{
		cnt = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < n; i++)
			cnt += pa[i] / mid;
		if (cnt < m)
			right = mid - 1;
		else
			left = mid + 1;
	}
	sum -= right * m;
	printf("%lld", sum);
	return 0;
}