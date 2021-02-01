//SCC - 타잔 알고리즘
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
int V, E, schk[10005], scc[10005], S, cnt;
vector<vector<int>> v, ans;
stack<int> st;
int dfs(int now) {
	st.push(now);
	schk[now] = S++;
	int parent = schk[now];
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (schk[next] == -1) parent = min(parent, dfs(next));
		else if (scc[next] == -1) parent = min(parent, schk[next]);
	}
	if (parent == schk[now]) {
		vector<int> vscc;
		while (1) {
			int here = st.top();
			st.pop();
			scc[here] = cnt;
			vscc.push_back(here);
			if (here == now) break;
		}
		sort(vscc.begin(), vscc.end());
	}	ans.push_back(vscc);
		cnt++;
	}
	return parent;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(schk, -1, sizeof(schk));
	memset(scc, -1, sizeof(scc));
	cin >> V >> E;
	v.resize(V + 1);
	for (int i = 0; i < E; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= V; i++)
		if (schk[i] == -1) dfs(i);
	cout << cnt << '\n';
	sort(ans.begin(), ans.end());
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << ' ';
		cout << "-1\n";
	}
	return 0;
