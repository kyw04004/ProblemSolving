#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
bool cycle;
int n, m, a, b, c, dist[501];
vector<vector<pair<int,int>>> v(501);
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
	}
	for (int i = 1; i <= n; i++)
		dist[i] = 1e9;
	dist[1] = 0;
	bool cycle = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < v[i].size(); j++)
			{
				int next = v[i][j].first;
				int nextcost = v[i][j].second;
				if (dist[i] != 1e9&&dist[next] > dist[i] + nextcost)
				{
					dist[next] = dist[i] + nextcost;
					if (k == n) cycle = 1;
				}
			}
	if (cycle == 1) 
		printf("-1");
	else
		for (int i = 2; i <= n; i++)
		{
			if (dist[i] == 1e9)
				printf("-1\n");
			else
				printf("%d\n", dist[i]);
		}
	return 0;
}