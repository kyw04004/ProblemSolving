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
int n, m,a,b,c,sum;
int parent[1005];
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
	if (a == b) return;
	parent[b] = a;
	sum += c;
}
void kruskal()
{
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int to = pq.top().second.first;
		int from = pq.top().second.second;
		pq.pop();
		merge(to, from, cost);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		pq.push({ c,{a,b} });
	}
	kruskal();
	printf("%d", sum);
	return 0;
}