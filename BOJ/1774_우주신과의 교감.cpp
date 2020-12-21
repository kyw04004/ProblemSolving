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
#include<stack>
using namespace std;
int n, m, a, b, c, cnt;
double sum;
int parent[1005];
typedef pair<double, pair<int, int>> P;
priority_queue<P, vector<P>, greater<P>> pq;
pair<int, int> d[1005];
int find(int n)
{
	if (parent[n] < 0) return n;
	parent[n] = find(parent[n]);
	return parent[n];
}
void merge(int a, int b, double c)
{
	int x = a;
	int y = b;
	a = find(a);
	b = find(b);
	if (a == b) return;
	sum += c;
	parent[b] = a;
}
void kruskal()
{
	while (!pq.empty())
	{
		double cost = pq.top().first;
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
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &d[i].first, &d[i].second);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &a, &b);
		pq.push({ 0,{a,b} });
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			long long dx = (d[i].first - d[j].first);
			long long dy = (d[i].second - d[j].second);
			double d = sqrt(dx*dx + dy * dy);
			pq.push({ d,{i,j} });
		}
	}
	kruskal();
	printf("%.2lf\n", sum);
	return 0;
}