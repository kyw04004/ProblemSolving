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
int N, schk[105], scc[105], S, cnt, cost[105];
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
		//sort(vscc.begin(), vscc.end());
		ans.push_back(vscc);
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
	cin >> N;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) cin >> cost[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char a; cin >> a;
			if (a == '1') v[i].push_back(j);
		}
	}
	for (int i = 1; i <= N; i++)
		if (schk[i] == -1) dfs(i);
	//sort(ans.begin(), ans.end());
	int sum = 0;
	for (int i = 0; i < cnt; i++) {
		int m = 1e6;
		for (int j = 0; j < ans[i].size(); j++)
			m = min(m, cost[ans[i][j]]);
		sum += m;
	}
	cout << sum;
	return 0;
}