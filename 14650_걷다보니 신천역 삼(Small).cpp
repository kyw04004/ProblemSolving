#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int n, cnt;
queue <pair<int,int>> q;
void bfs(int now, int depth)
{
	q.push({ now,depth });
	while (!q.empty())
	{
		int here = q.front().first;
		int dep = q.front().second;
		q.pop();
		if (dep == n)
		{
			if (here % 3 == 0) cnt++;
			continue;
		}
		for (int i = 0; i <= 2; i++)
		{
			if (here * 10 + i == 0) continue;
			q.push({ here * 10 + i,dep + 1 });
		}
	}
}
int main()
{
	cin >> n;
	bfs(0, 0);
	printf("%d\n",cnt);
	return 0;
}