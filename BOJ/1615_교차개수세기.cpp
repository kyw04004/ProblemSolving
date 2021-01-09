#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
vector<int> tree;
vector<pair<int, int>> input;
int n, m, h, x, y;
int update(int idx, int val, int left, int right, int node)
{
	if (left > idx || idx > right) return tree[node];
	if (left == right) return tree[node] += val;
	int mid = (left + right) / 2;
	return tree[node] = update(idx, val, left, mid, node * 2) + update(idx, val, mid + 1, right, node * 2 + 1);
}
ll query(int now, int start, int end)
{
	if (end < x || y < start) return 0;
	if (x <= start && end <= y) return tree[now];
	int mid = (start + end) / 2;
	return query(now * 2, start, mid) + query(now * 2 + 1, mid + 1, end);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2, 0);
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		input.push_back({ a,b });
	}
	sort(input.begin(),input.end());
	ll ans = 0;
	for (int i = 0; i < m; i++) {
		int com = input[i].second;
		x = com + 1, y = n;
		ans += query(1, 1, n);
		update(com, 1, 1, n, 1);
	}
	cout << ans;
	return 0;
}