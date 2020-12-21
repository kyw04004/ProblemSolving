#include<stdio.h>
#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int chk[100001];
queue<pair<int, int>> q;
int a, b, n, m, cnt;
void bfs(int x)
{
	chk[x] = 1;
	q.push({ x,0 });
	while (!q.empty())
	{
		x = q.front().first;
		cnt = q.front().second;
		q.pop();
		if (x == m)
			break;
		else
		{
			if (x + 1 >= 0 && x + 1 <= 100000 && chk[x + 1] == 0)
			{
				chk[x + 1] = 1;
				q.push({ x + 1,cnt + 1 });
			}
			if (x - 1 >= 0 && x - 1 <= 100000 && chk[x - 1] == 0)
			{
				chk[x - 1] = 1;
				q.push({ x - 1,cnt + 1 });
			}
			if (x + a >= 0 && x + a <= 100000 && chk[x + a] == 0)
			{
				chk[x + a] = 1;
				q.push({ x + a,cnt + 1 });
			}
			if (x - a >= 0 && x - a <= 100000 && chk[x - a] == 0)
			{
				chk[x - a] = 1;
				q.push({ x - a,cnt + 1 });
			}
			if (x + b >= 0 && x + b <= 100000 && chk[x + b] == 0)
			{
				chk[x + b] = 1;
				q.push({ x + b,cnt + 1 });
			}
			if (x - b >= 0 && x - b <= 100000 && chk[x - b] == 0)
			{
				chk[x - b] = 1;
				q.push({ x - b,cnt + 1 });
			}
			if (a*x >= 0 && a*x <= 100000 && chk[a*x] == 0)
			{
				chk[a*x] = 1;
				q.push({ a*x,cnt + 1 });
			}
			if (b*x >= 0 && b*x <= 100000 && chk[b*x] == 0)
			{
				chk[b*x] = 1;
				q.push({ b*x,cnt + 1 });
			}
		}
	}
}
int main()
{
	cin >> a >> b >> n >> m;
	bfs(n);
	printf("%d", cnt);
	return 0;
}