#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		queue <pair<int,int>> q;
		priority_queue <int, vector<int>, less<int>> pq;
		int n, m, val,cnt=1,ok=0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
			q.push({ a,i });
			pq.push(a);
			if (i == m)
				val = a;
		}
		while (!pq.empty())
		{
			if (ok == 1)
				break;
			int v = pq.top();
			pq.pop();
			while (!q.empty())
			{
				if (v == q.front().first)
				{
					if (q.front().first == val && q.front().second == m)
					{
						ok = 1;
						break;
					}
					q.pop();
					cnt++;
					break;
				}
				if (v != q.front().first)
				{ 
					q.push(q.front());
					q.pop();
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}