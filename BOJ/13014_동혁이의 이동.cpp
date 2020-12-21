#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
int n, k, a, b, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
map <pair<int, int>, int> m;
queue <pair<pair<int, int>, int>> q;
void bfs(int x, int y)
{
	q.push({ {x,y},0 });
	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (cnt == k)
		{
			if (x > M)
				M = x;
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (m[{nx, ny}] != 1)
				{
					m[{nx, ny}] = 1;
					q.push({ {nx,ny},cnt + 1 });
				}
			}
		}
	}
}
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		m[{a, b}] = 1;
	}
	if (n == 0)
		printf("%d", k);
	else
	{
		bfs(0, 0);
		printf("%d", M);
	}
	return 0;
}
