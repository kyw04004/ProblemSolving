#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
vector<int> v[200001];
int N, Q, ncycle[200001], ind[200001], treenum[200001], num = 1;
queue<int> q, s;
void dfs(int now, int num) {
	treenum[now] = num;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (!treenum[next] && ncycle[next])
			dfs(next, num);
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		ind[a]++, ind[b]++;
	}
	for (int i = 1; i <= N; i++)
		if (ind[i] == 1) q.push(i);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		ncycle[now] = 1;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			ind[next]--;
			if (!ncycle[next] && ind[next] == 1) q.push(next);
		}
	}
	for (int i = 1; i <= N; i++)
		if (!ncycle[i]) s.push(i);
	while (!s.empty()) {
		int now = s.front();
		s.pop();
		if (!treenum[now]) dfs(now, num++);
	}
	for (int i = 0; i < Q; i++) {
		int a, b; cin >> a >> b;
		if (treenum[a] == treenum[b]) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
	return 0;
}