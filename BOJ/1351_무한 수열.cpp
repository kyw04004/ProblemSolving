#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
map <long long, long long> m;
long long dfs(long long n, long long p, long long q)
{
	if (n == 0)
		return 1;
	if (m[n]) return m[n];
	else
		return m[n]=dfs(n / p, p, q) + dfs(n / q, p, q);
}
int main()
{
	long long n, p, q;
	scanf("%lld%lld%lld",&n,&p,&q);
	printf("%lld", dfs(n, p, q));
	return 0;
}