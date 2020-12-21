#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n, m, time, a, b,win,ans,chk2[101][101][2];
int arr[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<pair<int,int>,pair<int,int>>> q;
void bfs(int x, int y)
{
	chk2[x][y][0] = 1;
	q.push({ { x,y },{0,0 } });
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		int cnt = q.front().second.first;
		int ans = q.front().second.second;
		q.pop();
		if (x == n && y == m && cnt <= time)
		{
			win = 1;
			printf("%d", cnt);
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (ans == 1 && nx >= 1 && nx <= n && ny >= 1 && ny <= m && chk2[nx][ny][ans] == 0)
			{
				chk2[nx][ny][ans] = 1;
				q.push({ { nx,ny },{cnt + 1,ans} });
			}
			if (ans==0&&nx >= 1 && nx <= n && ny >= 1 && ny <= m && chk2[nx][ny][ans] == 0&&(arr[nx][ny]==0||arr[nx][ny]==2))
			{
				if (arr[nx][ny] == 2)
				{
					chk2[nx][ny][ans+1] = 1;
					q.push({ { nx,ny },{cnt + 1,ans+1} });
				}
				else
				{
					chk2[nx][ny][ans] = 1;
					q.push({ { nx,ny },{cnt + 1,ans} });
				}
			}
		}
	}
}
int main()
{
	cin >> n >> m >> time;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(" %d", &arr[i][j]);
	bfs(1, 1);
	if (win == 0)
		printf("Fail");
	return 0;
}