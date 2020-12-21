#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
int main()
{
	int V, E,Min=1e9;
	int dist[401][401];
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			dist[i][j] = 1e9;
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
		if (dist[i][i] < Min)
			Min = dist[i][i];
	if (Min == 1e9)
		printf("-1");
	else
		printf("%d", Min);
	return 0;
}