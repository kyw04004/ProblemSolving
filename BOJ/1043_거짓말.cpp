#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
vector<vector<int>> v(51);
vector<vector<int>> input(51);
queue <int> q;
int n, m, s, cnt,chk[51];
void bfs()
{
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			if (chk[next] == 0)
			{
				chk[next] = 1;
				q.push(next);
			}
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	scanf("%d", &s);
	for (int i = 1; i <= s; i++)
	{
		int st;
		scanf("%d", &st);
		q.push(st);
		chk[st] = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		int a,b,c;
		scanf("%d", &a);
		scanf("%d", &b);
		input[i].push_back(b);
		for (int j = 2; j <= a; j++)
		{
			scanf("%d", &c);
			v[b].push_back(c);
			v[c].push_back(b);
			input[i].push_back(c);
		}
	}
	bfs();
	cnt = m;
	for(int i=1;i<=m;i++)
		for (int j = 0; j < input[i].size(); j++)
			if (chk[input[i][j]] == 1)
			{
				cnt--;
				j = 51;
			}
	printf("%d", cnt);
	return 0;
}