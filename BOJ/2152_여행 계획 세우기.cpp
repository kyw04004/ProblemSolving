//SCC -  Tarjan
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
int n, m, s, t,S, schk[10005], scc[10005], cnt, cost[10005], dp[10005];
vector<vector<int>> v, ans, sccv;
vector<pair<int, int>> input;
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
		vector<int> temp;
		while (1) {
			int here = st.top();
			st.pop();
			scc[here] = cnt;
			temp.push_back(here);
			if (here == now) break;
		}
		ans.push_back(temp);
		cnt++;
	}
	return parent;
}
void go(int now) {
	for (int i = 0; i < sccv[now].size(); i++) {
		int next = sccv[now][i];
		if (dp[next] < dp[now] + cost[next]) {
			dp[next] = dp[now] + cost[next];
			go(next);
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> s >> t;
	v.resize(n + 1);
	memset(schk, -1, sizeof(schk));
	memset(scc, -1, sizeof(scc));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		input.push_back({ a,b });
	}
	for (int i = 1; i <= n; i++)
		if (schk[i] == -1) dfs(i);
	sccv.resize(cnt + 1);
	for (int i = 0; i < cnt; i++) cost[i] = ans[i].size();
	for (int i = 0; i < input.size(); i++) { 
		int s = input[i].first;
		int e = input[i].second;
		if (scc[s] == scc[e]) continue;
		sccv[scc[s]].push_back(scc[e]);
	}
	dp[scc[s]] = cost[scc[s]];
	go(scc[s]);
	cout << dp[scc[t]];
	return 0;
}