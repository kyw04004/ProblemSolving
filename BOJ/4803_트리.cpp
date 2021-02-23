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
int chk[505], ncnt,ecnt;
vector<vector<int>> v;
void dfs(int before, int now) {
	chk[now] = 1;
	ncnt++;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (before == next) continue;
		if (chk[next]) {
			ecnt++;
			continue;
		}
		ecnt++;
		dfs(now, next);
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int T = 1;;T++) {
		int n, m;
		cin >> n >> m;
		if (n + m == 0) break;
		v.clear();
		v.resize(n+1);
		for (int i = 1; i <= m; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		int tree = 0;
		memset(chk, 0, sizeof(chk));
		for (int i = 1; i <= n; i++) {
			if (!chk[i]) {
				ncnt = 0, ecnt = 0;
				dfs(-1, i);
				if (ncnt == ecnt + 1) tree++;
			}
		}
		if (tree == 0) printf("Case %d: No trees.\n", T, tree);
		else if (tree == 1) printf("Case %d: There is one tree.\n", T, tree);
		else printf("Case %d: A forest of %d trees.\n", T, tree);
	}
	return 0;
}