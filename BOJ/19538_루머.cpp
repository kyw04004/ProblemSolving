#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector <int> v[200001];
queue <pair<int, int>> q;
int n, m, chk[200001], ans[200001], in[200001];
void bfs() {
	while (!q.empty()) {
		int now = q.front().first;
		int time = q.front().second;
		ans[now] = time;
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			in[next]++;
			int len = v[next].size();
			if (len % 2 == 1) len++;
			len /= 2;
			if (!chk[next] && in[next] >= len) {
				chk[next] = 1;
				q.push({ next,time + 1 });
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		while (1) {
			int a;
			cin >> a;
			if (a == 0) break;
			v[i].push_back(a);
		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a;
		cin >> a;
		q.push({ a,0 });
		chk[a] = 1;
	}
	bfs();
	for (int i = 1; i <= n; i++) {
		if (chk[i] == 0) ans[i] = -1;
		printf("%d ", ans[i]);
	}
	return 0;
}