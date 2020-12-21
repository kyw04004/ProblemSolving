#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int t, n, chk[20001],dx[2] = {0,1},ok;
queue <pair<pair<int, string>,int>> q;
void bfs(int mod)
{
	chk[1] = 1;
	q.push({ { 1,"1" },1 });
	while (!q.empty())
	{
		int now = q.front().first.first;
		string nowstr = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (now == 0 && cnt<=100)
		{
			ok = 1;
			cout << nowstr << "\n";
			break;
		}
		for (int i = 0; i < 2; i++)
		{
			int next = (now*10+dx[i])%mod;
			string nextstr = nowstr;
			if (i == 0)
				nextstr += "0";
			if (i == 1)
				nextstr += "1";
			if (chk[next] == 0)
			{
				chk[next] = 1;
				q.push({ { next,nextstr },cnt + 1 });
			}
		}
	}
	if (ok == 0)
		printf("BRAK\n");
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		ok = 0;
		memset(chk, 0, sizeof(chk));
		if (n == 1)
		{
			printf("1\n");
			continue;
		}
		bfs(n);
		while (!q.empty())
			q.pop();
	}
	return 0;
}