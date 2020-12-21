#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
int n, m,a,b,cnt,sum;
int chk[100];
vector<vector<int>> v1(100);
vector<vector<int>> v2(100);
void dfs(int x)
{
	chk[x] = 1;
	for (int i = 0; i < v1[x].size(); i++)
	{
		int next = v1[x][i];
		if (chk[next] == 0)
		{
			cnt+=1;
			dfs(next);
		}
	}
}
void dfs2(int x)
{
	chk[x] = 1;
	for (int i = 0; i < v2[x].size(); i++)
	{
		int next = v2[x][i];
		if (chk[next] == 0)
		{
			cnt += 1;
			dfs2(next);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		v1[a].push_back(b);
		v2[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		cnt = 0;
		dfs(i);
		memset(chk, 0, sizeof(chk));
		if (cnt > n / 2)
			sum++;
		cnt = 0;
		dfs2(i);
		memset(chk, 0, sizeof(chk));
		if (cnt > n / 2)
			sum++;
	}
	printf("%d", sum);
	return 0;
}
