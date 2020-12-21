#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
ll n, m,sum;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main()
{
	scanf(" %lld %lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		ll x;
		scanf(" %lld", &x);
		pq.push(x);
	}
	for (int i = 1; i <= m; i++)
	{
		ll a = pq.top();
		pq.pop();
		ll b = pq.top();
		pq.pop();
		pq.push(a + b);
		pq.push(a + b);
	}
	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}
	printf("%lld", sum);
	return 0;
}