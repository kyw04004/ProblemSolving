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
int n,m, level[105], work[105], S, E, ans, c[105][105], f[105][105];
vector<int> v[105];
bool bfs() {
	memset(level, -1, sizeof(level));
	level[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (level[next] == -1 && c[now][next] - f[now][next] > 0) {
				level[next] = level[now] + 1;
				q.push(next);
			}
		}
	}
	return level[E] != -1;
}
int dfs(int now, int flow) {
	if (now == E) return flow;
	for (int &i = work[now]; i < v[now].size(); i++) {
		int next = v[now][i];
		if (level[now] + 1 == level[next] && c[now][next] - f[now][next] > 0) {
			int ret = dfs(next, min(flow, c[now][next] - f[now][next]));
			if (ret > 0) {
				f[now][next] += ret;
				f[next][now] -= ret;
				return ret;
			}
		}
	}
	return 0;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	S = 0, E = n + m + 1;
	vector<int> capa;
	for (int i = 1; i <= n; i++) {
		int val; cin >> val;
		capa.push_back(val);
		v[i].push_back(E);
		c[i][E] += 1e7;
	}
	for (int i = n+1; i <= n+m; i++) {
		int val; cin >> val;
		capa.push_back(val);
		v[S].push_back(i);
		c[S][i] += val;
	}
	for (int i = n + 1; i <= n + m; i++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j++) {
			int num; cin >> num;
			v[i].push_back(num);
			c[i][num] += capa[num - 1];
		}
	}
	while (bfs()) {
		memset(work, 0, sizeof(work));
		while (1) {
			int flow = dfs(S, 1e9);
			if (!flow) break;
			ans += flow;
		}
	}
	cout << ans;
	return 0;
}