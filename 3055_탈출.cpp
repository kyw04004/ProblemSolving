#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
using namespace std;
queue<pair<pair<int,int>, int>> q;
char Map[55][55];
int a, b;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int chk[55][55];
void bfs(int x, int y, int cnt)
{
	chk[x][y] = 1;
	q.push({ {x,y},0 });
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (Map[x][y] == 'D')
		{
			printf("%d\n", cnt);
			return;
		}
		if (cnt == -1)
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (Map[nx][ny]=='X'||Map[nx][ny]=='D'||chk[nx][ny]==1||Map[nx][ny] == '*' || nx > a || nx<1 || ny>b || ny < 1) continue;
				if (Map[nx][ny] == '.')
				{
					Map[nx][ny] = '*';
					q.push({ {nx,ny},-1 });
				}
			}
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (Map[nx][ny] == 'X' || chk[nx][ny] == 1 || Map[nx][ny] == '*' || nx > a || nx<1 || ny>b || ny < 1) continue;
				chk[nx][ny] = 1;
				q.push({ { nx,ny }, cnt + 1 });
			}
		}
	}
	printf("KAKTUS\n");
	return;
}
int main()
{
	cin >> a >> b;
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			cin >> Map[i][j];
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			if (Map[i][j] == '*')
				q.push({ {i,j},-1 });
	for (int i = 1; i <= a; i++)
		for (int j = 1; j <= b; j++)
			if (Map[i][j] == 'S')
				bfs(i, j, 0);
	return 0;
}