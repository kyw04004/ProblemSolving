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
int parent[105];
typedef pair<double, pair<int, int>> P;
priority_queue<P, vector<P>, greater<P>> pq;
pair<double, double> d[105];
int find(int n) // 루트노드찾기
{
	if (parent[n] < 0) return n;
	parent[n] = find(parent[n]);
	return parent[n];
}
void merge(int a, int b, double c) // 이어주기
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
	cin >> n;
	for (int i = 1; i <= n; i++)
		parent[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf%lf", &d[i].first,&d[i].second);
		//printf("%f %f\n", d[i].first, d[i].second);
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			double dx = (d[i].first - d[j].first);
			double dy = (d[i].second - d[j].second);
			double d = sqrt(dx*dx + dy * dy);
			//printf("%0.2f\n", d);
			pq.push({ d,{i,j} });
		}
	}
	kruskal();
	printf("%.2lf\n", sum);
	return 0;
}