#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
int n, m, map[105][105], chk[105][105][2];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
priority_queue<pair<pair<int, int>, pair<int, int>>,vector<pair<pair<int, int>, pair<int, int>>>,greater<pair<pair<int, int>, pair<int, int>>>> pq;
int bfs(int x, int y, int Max, int cnt)
{
	chk[x][y][cnt] = 1;
	pq.push({ {Max,cnt},{x,y} });
	while (!pq.empty())
	{
		int X = pq.top().second.first;
		int Y = pq.top().second.second;
		int MAX = pq.top().first.first;
		int C = pq.top().first.second;
		pq.pop();
		if (X == n && Y == m) return MAX;
		for (int i = 0; i < 4; i++)
		{
			int nx = X + dx[i];
			int ny = Y + dy[i];
			int mx = nx + dx[i];
			int my = ny + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !chk[nx][ny][C])
			{
				chk[nx][ny][C] = 1;
				pq.push({ {max(MAX,map[nx][ny]),C},{nx,ny} });
			}
			if (mx >= 1 && mx <= n && my >= 1 && my <= m && !C && !chk[mx][my][C + 1])
			{
				chk[mx][my][C+1] = 1;
				pq.push({ {max(MAX,map[mx][my]),C + 1},{mx,my} });
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> map[i][j];
	printf("%d\n", bfs(1, 1, map[1][1], 0));
	return 0;
}