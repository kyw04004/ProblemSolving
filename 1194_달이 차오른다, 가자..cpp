#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
queue <pair<pair<int, int>, pair<int, int>>> q;
int n, m;
char Map[55][55];
int chk[55][55][(1 << 5)+1];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int bfs(int a, int b)
{
	q.push({ {a,b},{0,0} });
	chk[a][b][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int key = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (Map[x][y] == '1') return cnt;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (chk[nx][ny][key]||nx<1 || nx>n || ny<1 || ny>m || Map[nx][ny] == '#') continue;
			if (Map[nx][ny] >= 'a' && Map[nx][ny] <= 'f')
			{
				int nkey = (key | (1 << (Map[nx][ny] - 'a')));
				chk[nx][ny][nkey] = 1;
				q.push({ { nx,ny }, {nkey,cnt + 1} });
			}
			else if (Map[nx][ny] >= 'A' && Map[nx][ny] <= 'F' && (key & (1 << (Map[nx][ny] - 'A'))))
			{
				chk[nx][ny][key] = 1;
				q.push({ { nx,ny },  {key,cnt + 1} });
			}
			else
			{
				chk[nx][ny][key] = 1;
				q.push({ { nx,ny }, {key,cnt + 1} });
			}
		}
	}
	return -1;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(" %c", &Map[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (Map[i][j] == '0')
				printf("%d\n", bfs(i,j));
	return 0;
}