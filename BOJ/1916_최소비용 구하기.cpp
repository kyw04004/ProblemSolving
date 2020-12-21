#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
bool cycle;
int n, m, a, b, c, dist[1001];
vector<vector<pair<int,int>>> v(1001);
void bell(int st)
{
	for (int i = 1; i <= n; i++)
		dist[i] = 1e9;
	dist[st] = 0;
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
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
	}
	cin >> a >> b;
	bell(a);
	printf("%d", dist[b]);
	return 0;
}