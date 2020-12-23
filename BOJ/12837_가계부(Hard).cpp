#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
vector<ll> tree;
ll n, m, h, x, y;
ll update(ll idx, ll val, ll left, ll right, ll node)
{
	if (left > idx || idx > right) return tree[node];
	if (left == right) return tree[node] += val;
	ll mid = (left + right) / 2;
	return tree[node] = update(idx, val, left, mid, node * 2)+update(idx, val, mid + 1, right, node * 2 + 1);
}
ll query(ll node, ll start, ll end)
{
	if (end < x || y < start) return 0;
	if (x <= start && end <= y) return tree[node];
	ll mid = (start + end) / 2;
	return query(node * 2, start, mid)+query(node * 2 + 1, mid + 1, end);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	h = (1 << (ll)log2(n - 1) + 1);
	tree.resize(h * 2, 0);
	for (ll i = 1; i <= m; i++) {
		ll s, a, b;
		cin >> s >> a >> b;
		if (s == 1) update(a, b, 1, n, 1);
		if (s == 2) {
			x = a, y = b;
			cout << query(1, 1, n) << '\n';
		}
	}
	return 0;
}