#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int n, m, depth[40005], parent[40005][17],dist[40005];
vector<pair<int,int>> v[40005];
void dfs(int now, int dep) {
	depth[now] = dep;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i].first;
		int nextcost = v[now][i].second;
		if (!depth[next]) {
			dist[next] = dist[now] + nextcost;
			parent[next][0] = now;
			dfs(next, dep + 1);
		}
	}
}
int LCA(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	for (int i = 16; i >= 0; i--)
		if (depth[a] <= depth[parent[b][i]])
			b = parent[b][i];
	if (a == b) return a;
	for (int i = 16; i >= 0; i--)
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	return parent[a][0];
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	dfs(1, 1);
	for (int j = 1; j <= 16; j++)
		for (int i = 1; i <= n; i++)
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		int lca = LCA(a, b);
		cout << dist[a] + dist[b] - 2*dist[lca] << '\n';
	}
	return 0;
}