#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
vector<pair<int, int>> v[1001];
int n, m ,dp[1001], path[1001];
int go(int now) {
	if (dp[now] != -1 && now == 1) return 0;
	int& ret = dp[now];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i].first;
		int nextcost = v[now][i].second;
		int com = go(next) + nextcost;
		if (com > ret) ret = com, path[now] = next;
	}
	return ret;
}
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	printf("%d\n", go(1));
	int here = 1;
	printf("%d ", here);
	while (1) {
		printf("%d ", path[here]);
		here = path[here];
		if (here == 1) break;
	}
	return 0;
}