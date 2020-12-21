#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
vector<pair<int, int>> v[50001];
int n, dist[50001],s,e,node,Max, arr[50001],chk[50001];
void dfs(int now) {
	chk[now] = 1;
	if (dist[now] > Max) Max = dist[now], node = now;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i].first;
		int nextcost = v[now][i].second;
		if (chk[next]) continue;
		dist[next] += (dist[now] + nextcost);
		dfs(next);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1); s = node;
	memset(chk, 0, sizeof(chk));
	memset(dist, 0, sizeof(dist));
	dfs(s);
	for(int i=1;i<=n;i++) arr[i] = dist[i];
	e = node, Max = 0;
	memset(chk, 0, sizeof(chk));
	memset(dist, 0, sizeof(dist));
	dfs(e);
	for (int i = 1; i <= n; i++) cout << max(arr[i], dist[i]) << "\n";
	return 0;
}