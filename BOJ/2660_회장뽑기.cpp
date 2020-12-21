#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
int dist[51][51];
int Min = 1e9,Max,cnt;
int arr[51];
int main()
{
	int n,a,b;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = 1e9;
	for (int j = 1; j <= n; j++)
		dist[j][j] = 0;
	while (1)
	{
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i == j) continue;
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
	for (int i = 1; i <= n; i++)
	{
		Max = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (dist[i][j] > Max)
				Max = dist[i][j];
		}
		if (Max < Min)
			Min = Max;
	}
	for (int i = 1; i <= n; i++)
	{
		Max = 0;
		for (int j = 1; j <= n; j++)
		{
			if (Max<dist[i][j])
			{
				Max = dist[i][j];
			}
		}
		if (Max == Min)
		{
			for (int j = 1; j <= n; j++)
			{
				if (Min == dist[i][j])
				{
					arr[cnt] = i;
					cnt++;
					break;
				}
			}
		}
	}
	printf("%d %d\n", Min,cnt);
	for (int i = 0; i < cnt; i++)
		printf("%d ", arr[i]);
	return 0;
}