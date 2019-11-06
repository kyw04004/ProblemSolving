#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
bool cycle;
int n, m, a, b, c, dist[1001], cnt;
int past[1001];
stack <int> s;
vector<vector<pair<int, int>>> v(1001);
void bell(int st)
{
	for (int i = 1; i <= n; i++)
		dist[i] = 1e9;
	dist[st] = 0;
	bool cycle = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < v[i].size(); j++)
			{
				int next = v[i][j].first;
				int nextcost = v[i][j].second;
				if (dist[i] != 1e9&&dist[next] > dist[i] + nextcost)
				{
					dist[next] = dist[i] + nextcost;
					past[next] = i;
					if (k == n) cycle = 1;
				}
			}
}
void go(int a, int b)
{
	if (b == a)
	{
		s.push(b);
		cnt++;
		return;
	}
	if (past[b] != 0)
	{
		s.push(b);
		cnt++;
		go(a, past[b]);
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back({ b,c });
	}
	cin >> a >> b;
	bell(a);
	go(a, b);
	printf("%d\n", dist[b]);
	printf("%d\n", cnt);
	while (!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}