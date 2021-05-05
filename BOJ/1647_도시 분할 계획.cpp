#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, pair<int, int>> P;
priority_queue<P, vector<P>, greater<P>> pq;
int V, E, parent[100005],ans, Max;
int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	parent[y] = x;
}
bool isUnion(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return true;
	else return false;
}
void kruskal() {
	while (!pq.empty()) {
		int x = pq.top().second.first, y = pq.top().second.second;
		if (!isUnion(x, y)) {
			merge(x, y);
			ans += pq.top().first;
			Max = max(Max, pq.top().first);
		}
		pq.pop();
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> V >> E;
	for (int i = 1; i <= V; i++) parent[i] = i;
	for (int i = 1; i <= E; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		pq.push({ w, {s, e} });
	}
	kruskal();
	cout << ans - Max;
	return 0;
}