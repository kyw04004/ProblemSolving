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
int n, m, chk[205],ok;
vector<vector<int>> v;
vector<int> dst;
void dfs(int now, int d) {
	chk[now] = 1;
	if (ok) return;
	if (now == d) {
		ok = 1;
		return;
	}
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (chk[next]) continue;
		dfs(next, d);
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int c; cin >> c;
			if (c == 1) v[i].push_back(j);
		}
	}
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		dst.push_back(a);
	}
	for (int i = 0; i < m - 1; i++) {
		ok = 0;
		memset(chk, 0, sizeof(chk));
		if (dst[i] == dst[i + 1]) ok=1;
		else dfs(dst[i], dst[i + 1]);
		if (!ok) {
			cout << "NO\n";
			break;
		}
		else if (i == m - 2) cout << "YES\n";
	}
	return 0;
}
