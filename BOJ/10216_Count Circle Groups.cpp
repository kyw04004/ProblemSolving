#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int parent[3001];
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
int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<pair<pair<int, int>, int>> v;
		int N, x, y, R, chk[3001] = { 0, }, cnt = 0;
		cin >> N;
		for (int i = 1; i <= N; i++) parent[i] = i;
		for (int i = 1; i <= N; i++) {
			cin >> x >> y >> R;
			v.push_back({ {x,y},R });
		}
		for (int i = 0; i < v.size() - 1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (isUnion(i + 1, j + 1)) continue;
				else {
					int x1 = v[i].first.first;
					int y1 = v[i].first.second;
					int r1 = v[i].second;
					int x2 = v[j].first.first;
					int y2 = v[j].first.second;
					int r2 = v[j].second;
					if (((r1 + r2) * (r1 + r2)) >= ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)))
						merge(i + 1, j + 1);
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			int p = find(i);
			if (chk[p] == 0) chk[p] = 1, cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}