#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;
int dist[501][501];
int main()
{
	int n, t, a, b, chk = 1, cnt = 0;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = 1e9;
	for (int j = 1; j <= n; j++)
		dist[j][j] = 0;
	for (int i = 1; i <= t; i++)
	{
		cin >> a >> b;
		dist[a][b] = 1;
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
		chk = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (dist[i][j] == 1e9 && dist[j][i] == 1e9)
				chk = 1;
		}
		if (chk == 0)
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}