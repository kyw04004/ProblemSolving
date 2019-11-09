#include<stdio.h>
#include<iostream>
using namespace std;
int chk[505][505];
char arr[505][505];
int win[505][505];
int n, m,s,sum,c;
void dfs(int x, int y)
{
	chk[x][y] = 1;
	s++;
	if (x<1 || x>n || y<1 || y>m||win[x][y]==1)
	{
		s--;
		sum += s;
		c = 1;
		return;
	}
	else {
		if (arr[x][y] == 'U')
		{
			x -= 1;
			if (chk[x][y] == 0||win[x][y]==1)
			{
				dfs(x, y);
				if (c == 1)
				{
					x += 1;
					win[x][y] = 1;
				}
			}
		}
		if (arr[x][y] == 'R')
		{
			y += 1;
			if (chk[x][y] == 0 || win[x][y] == 1)
			{
				dfs(x, y);
				if (c == 1)
				{
					y -= 1;
					win[x][y] = 1;
				}

			}
		}
		if (arr[x][y] == 'D')
		{
			x += 1;
			if (chk[x][y] == 0 || win[x][y] == 1)
			{
				dfs(x, y);
				if (c == 1)
				{
					x -= 1;
					win[x][y] = 1;
				}
			}
		}
		if (arr[x][y] == 'L')
		{
			y -= 1;
			if (chk[x][y] == 0 || win[x][y] == 1)
			{
				dfs(x, y);
				if (c == 1)
				{
					y += 1;
					win[x][y] = 1;
				}
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (chk[i][j] == 0)
			{
				s = 0;
				c = 0;
				dfs(i, j);
			}
	printf("%d", sum);
	return 0;
}