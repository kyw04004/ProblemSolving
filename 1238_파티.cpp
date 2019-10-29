#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
int V, E, X, Max;
int dist[1005][1005];
int main()
{
	scanf("%d%d%d", &V, &E, &X);
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			dist[i][j] = 1e9;
	for (int j = 1; j <= V; j++)
		dist[j][j] = 0;
	for (int i = 1; i <= E; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		dist[a][b] = c;
	}
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
	for (int i = 1; i <= V; i++)
		if ((dist[i][X] + dist[X][i]) > Max)
			Max = (dist[i][X] + dist[X][i]);
	printf("%d", Max);
	return 0;
}