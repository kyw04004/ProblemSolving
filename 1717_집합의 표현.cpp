#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
int n, m, a, b, c, sum;
int parent[1000005];
typedef pair<int, pair<int, int>> P;
priority_queue<P, vector<P>, greater<P>> pq;
int find(int n)
{
	if (parent[n] < 0) return n;
	parent[n] = find(parent[n]);
	return parent[n];
}
void merge(int a, int b, int c)
{
	a = find(a);
	b = find(b);
	if (a == b)
	{
		if (c == 1)
			printf("YES\n");
		return;
	}
	if (c == 1)
		printf("NO\n");
	if (c == 0)
		parent[b] = a;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
		parent[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		merge(b, c, a);
	}
	return 0;
}