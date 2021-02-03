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
int n, xl, yl, xb, yb, chk[100005][2], ans=1e9;
vector<int> v[100005];
vector<pair<int,int>> node;
priority_queue <pair<pair<int, int>, int>,
	vector <pair<pair<int, int>, int>>,
	greater<pair<pair<int, int>, int>>> pq;
struct Point{
	int s;
	int e;
	int index;
};
Point point1[100005], point2[100005];
bool compare(Point a, Point b) {
	if (a.s < b.s) return true;
	if (a.s == b.s && a.e < b.e) return true;
	return false;
}
void bfs(int index) {
	pq.push({ { 0, index },0 });
	while (!pq.empty()) {
		int cnt = pq.top().first.first;
		int now = pq.top().first.second;
		int d = pq.top().second;
		int x = node[now].first;
		int y = node[now].second;
		pq.pop();
		if (chk[now][d]) continue;
		chk[now][d] = 1;
		if (x == xb && y == yb) {
			ans = min(ans, cnt - 1);
			continue;
		}
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (chk[next][d]) continue;
			int nx = node[next].first;
			int ny = node[next].second;
			int nd;
			if (x != nx && y != ny) continue;
			if (x == nx) nd = 1;
			else nd = 2;
			if (d == nd) pq.push({ { cnt, next }, nd });
			else pq.push({ { cnt + 1, next }, nd });
		}
	}
	return;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> xl >> yl >> xb >> yb;
	node.push_back({ xl,yl });
	point1[0] = { xl, yl, 0};
	point2[0] = { yl, xl, 0 };
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		point1[i+1] = { a, b, i+1};
		point2[i+1] = { b, a, i+1 };
		node.push_back({ a,b });
	}
	node.push_back({ xb,yb });
	point1[n+1] = { xb, yb, n+1 };
	point2[n+1] = { yb, xb, n+1 };
	sort(point1, point1 + n + 2, compare);
	sort(point2, point2 + n + 2, compare);
	for (int i = 0; i <=n; i++) {
		if (point1[i].s == point1[i + 1].s) {
			v[point1[i].index].push_back(point1[i + 1].index);
			v[point1[i+1].index].push_back(point1[i].index);
		}
		if (point2[i].s == point2[i + 1].s) {
			v[point2[i].index].push_back(point2[i + 1].index);
			v[point2[i + 1].index].push_back(point2[i].index);
		}
	}
	bfs(0);
	if (ans == 1e9) cout << -1;
	else cout << ans;
	return 0;
}