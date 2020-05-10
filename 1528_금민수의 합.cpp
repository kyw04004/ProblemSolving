#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<functional>
#include<stack>
#include<vector>
using namespace std;
queue <int> q;
int n, trace[1000001],chk;
vector<int> ans;
vector<int> dol;
void make(int value)
{
	if (value > n) return;
	dol.push_back(value);
	make(value * 10 + 4);
	make(value * 10 + 7);
}
void bfs()
{
	q.push(0);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now > n) continue;
		if (now == n) return;
		for (int i = 1; i < dol.size(); i++)
		{
			int next = now + dol[i];
			if (next<=n && trace[next] == -1 )
			{
				trace[next] = dol[i];
				q.push(next);
			}
		}
	}
	printf("-1");
	chk = 1;
}
int main()
{
	cin >> n;
	make(0);
	sort(dol.begin(), dol.end());
	memset(trace, -1, sizeof(trace));
	bfs();
	while (n)
	{
		ans.push_back(trace[n]);
		n -= trace[n];
	}
	sort(ans.begin(), ans.end());
	if(chk==0)
		for (int i = 0; i < ans.size(); i++)
			printf("%d ", ans[i]);
	return 0;
}