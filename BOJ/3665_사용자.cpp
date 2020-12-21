#include<stdio.h>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
int a[501];
int indegree[501];
int v[501][501];
int ans[501];
queue<int> q;
int x, y, cycle, k = 1, no;
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0, s = 0, k = 1, no = 0;
		cycle = 0;
		memset(indegree, 0, sizeof(indegree));
		memset(v, -1, sizeof(v));
		memset(ans, 0, sizeof(ans));
		cin >> n;
		int cnt = n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				indegree[a[j]]++;
				v[a[i]][a[j]] = 1;
			}
		}
		cin >> s; // 순위변동
		for (int i = 1; i <= s; i++)
		{
			cin >> x >> y;
			if (v[x][y] == 1)
			{
				v[x][y] = 0;
				v[y][x] = 1;
				indegree[y]--;
				indegree[x]++;
			}
			else if (v[y][x] == 1)
			{
				v[y][x] = 0;
				v[x][y] = 1;
				indegree[x]--;
				indegree[y]++;
			}
		}
		for (int i = 1; i <= n; i++)
			if (indegree[i] == 0)
				q.push(i);
		while (!q.empty()) // 위상정렬
		{
			if (q.size() >= 2)
			{
				no = 1;
				break;
			}
			int now = q.front();
			q.pop();
			ans[k] = now;
			k++;
			for (int i = 1; i < 501; i++)
			{
				int next = v[now][i];
				if (next == 1)
				{
					indegree[i]--;
					if (indegree[i] == 0)
						q.push(i);
				}
			}
		}
		if (no == 1)
			printf("?");
		else if (k < n+1)
			printf("IMPOSSIBLE");
		else
			for (int i = 1; i <= n; i++)
				printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}