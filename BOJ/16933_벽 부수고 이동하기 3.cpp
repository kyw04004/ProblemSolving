#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n, m, k;
int chk[1001][1001][11];
int a[1001][1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue <pair<pair<int, int>, pair<int, int>>> q;
int bfs(int x, int y, int cnt, int ck)
{
	chk[x][y][ck] = 1;
	q.push({ {x,y},{cnt + 1,ck} });
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		cnt = q.front().second.first;
		ck = q.front().second.second;
		q.pop();
		if (x == n && y == m) return cnt;
		for (int i = 0; i < 4; i++)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && chk[xx][yy][ck] == 0)
			{
				if (a[xx][yy] == 0)
				{
					chk[xx][yy][ck] = 1;
					q.push({ {xx,yy },{cnt + 1,ck} });
				}
				else if (a[xx][yy] == 1 && ck < k)
				{
					if (cnt % 2 == 1)
					{
						chk[xx][yy][ck] = 1;
						q.push({ {xx,yy },{cnt + 1,ck + 1} });
					}
					else
						q.push({ {x,y },{cnt + 1,ck} });
				}
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &a[i][j]);
	printf("%d", bfs(1, 1, 0, 0));
	return 0;
}
