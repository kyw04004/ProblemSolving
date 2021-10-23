#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, Q;
vector<vector<pair<int,int>>> graph;
int usado[5005][5005];
void bfs(int st, int now, int Min) {
	queue<pair<int, int>> q;
	usado[st][now] = -1;
	q.push({ now, Min });
	while (!q.empty()) {
		int now = q.front().first;
		int Min = q.front().second;
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;
			if (usado[st][next] == 1e9) {
				usado[st][next] = min(Min, nextCost);
				q.push({ next, usado[st][next] });
			}
		}
	}
}
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> Q;
	graph.resize(N + 1);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			usado[i][j] = 1e9;
	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	for (int i = 1; i <= N; i++)
		bfs(i, i, 1e9);
	for (int i = 0; i < Q; i++) {
		int k, v; cin >> k >> v;
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (usado[v][j] == 1e9) continue;
			if (k <= usado[v][j]) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}