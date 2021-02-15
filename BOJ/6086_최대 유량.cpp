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
int n, level[705], work[705], S = 1, E = 26, ans, c[705][705], f[705][705];
vector<int> v[705];
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b;
		int val;
		cin >> a >> b >> val;
		if ('A' <= a) {
			a -= 'A';
			a += 1;
		}
		else {
			a -= 'a';
			a += 27;
		}
		if ('A' <= b) {
			b -= 'A';
			b += 1;
		}
		else {
			b -= 'a';
			b += 27;
		}
		v[a].push_back(b);
		v[b].push_back(a);
		c[a][b] += val;
		c[b][a] += val;
	}
	while (bfs()) {
		memset(work, 0, sizeof(work));
		while (1) {
			int flow = dfs(S,1e9);
			if (!flow) break;
			ans += flow;
		}
	}
	cout << ans;
	return 0;
}