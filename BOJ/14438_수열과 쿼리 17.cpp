#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
vector<int> tree;
int n, m, h, x, y;
int update(int idx, int val, int left, int right, int node)
{
	if (left > idx || idx > right) return tree[node];
	if (left == right) return tree[node] = val;
	int mid = (left + right) / 2;
	return tree[node] = min(update(idx, val, left, mid, node * 2), update(idx, val, mid + 1, right, node * 2 + 1));
}
int query(int now, int start, int end)
{
	if (end < x || y < start) return 1e9 + 5;
	if (x <= start && end <= y) return tree[now];
	int mid = (start + end) / 2;
	return min(query(now * 2, start, mid), query(now * 2 + 1, mid + 1, end));
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	h = (1 << (int)log2(n - 1) + 1);
	tree.resize(h * 2, 1e9 + 5);
	for (int i = 1; i <= n; i++) {
		int val; cin >> val; 
		update(i,val, 1, n, 1);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int s, a, b;
		cin >> s >> a >> b;
		if (s == 1) update(a, b, 1, n, 1);
		if (s == 2) {
			x = a, y = b;
			cout << query(1, 1, n) << '\n';
		}
	}
	return 0;
}