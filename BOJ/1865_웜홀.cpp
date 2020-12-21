#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
bool cycle;
typedef pair <int, int> P;
int n, m, a, b, c, t, h, dist[505];
vector<vector<P>> adj(505);
int main()
{
	scanf("%d", &t);
	for (int z = 1; z <= t; z++)
	{
		scanf("%d %d %d", &n, &m, &h);
		adj.clear();
		adj.resize(n + 1);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back({ b,c });
			adj[b].push_back({ a,c });
		}
		for (int i = 1; i <= h; i++)
		{
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back({ b,-c });
		}
		for (int i = 1; i <= n; i++) dist[i] = 1e9;
		dist[1] = 0;
		bool cycle = 0;
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 0; j < adj[i].size(); j++)
				{
					int next = adj[i][j].first;
					int nextcost = adj[i][j].second;
					if (dist[next] > dist[i] + nextcost)
					{
						dist[next] = dist[i] + nextcost;
						if (k == n) cycle = 1;
					}
				}
		if (cycle == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}