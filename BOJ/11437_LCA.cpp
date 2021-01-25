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
int n, m, depth[50005],parent[50005];
vector<int> v[50005];
void dfs(int now, int dep) {
	depth[now] = dep;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!depth[next]) {
			parent[next] = now;
			dfs(next, dep + 1);
		}
	}
}
int LCA(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	while (depth[a] != depth[b]) b = parent[b];
	while (a != b) {
		a = parent[a];
		b = parent[b];
	}
	return a;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 1);
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}