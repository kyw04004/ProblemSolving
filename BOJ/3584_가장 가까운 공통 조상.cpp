#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
vector<vector<int>> v;
int depth[10005], in[10005], parent[10005], ans, c1, c2;
void dfs(int now, int dep) {
	depth[now] = dep;
	for (int i = 0; i < v[now].size(); i++)
		dfs(v[now][i], dep + 1);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		memset(depth, 0, sizeof(depth));
		memset(in, 0, sizeof(in));
		v.clear();
		v.resize(N + 1);
		for (int i = 1; i <= N; i++) parent[i] = i;
		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			parent[b] = a;
			in[b]++;
		}
		cin >> c1 >> c2;
		for (int i = 1; i <= N; i++)
			if (in[i] == 0)
				dfs(i, 1);
		while (1) {
			if (depth[c1] == depth[c2]) {
				if (c1 == c2) {
					ans = c1;
					break;
				}
				else {
					c1 = parent[c1];
					c2 = parent[c2];
				}
			}
			else if (depth[c1] > depth[c2]) c1 = parent[c1];
			else c2 = parent[c2];
		}
		cout << ans << '\n';
	}
	return 0;
}