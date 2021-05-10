#include <iostream>
#include <vector>
using namespace std;
int n, m, h = 1;
typedef long long ll;
vector<ll> seg;
vector<ll> lazy;
void update(int idx, ll val) {
	idx += h - 1;
	seg[idx] += val;
	while (idx /= 2)
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}
void propagation(int node, int L, int R) {
	if (lazy[node] == 0) return;
	seg[node] += lazy[node] * (R - L + 1);
	if (R != L) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}
void queryLazy(int L, int R, int node, int S, int E, ll val) {
	propagation(node, S, E);
	if (R < S || E < L) return;
	if (L <= S && E <= R) {
		seg[node] += val * (E - S + 1);
		if (S != E) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (S + E) / 2;
	queryLazy(L, R, node * 2, S, mid, val);
	queryLazy(L, R, node * 2 + 1, mid + 1, E, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
ll querySum(int L, int R, int node, int S, int E) {
	propagation(node, S, E);
	if (R < S || E < L) return 0;
	if (L <= S && E <= R) return seg[node];
	int mid = (S + E) / 2;
	return querySum(L, R, node * 2, S, mid) + querySum(L, R, node * 2 + 1, mid + 1, E);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	while (n > h) h *= 2;
	seg.resize(h * 2);
	lazy.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		ll val; cin >> val;
		update(i, val);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c, d; cin >> a;
		if (a == 1) {
			cin >> b >> c >> d;
			queryLazy(b, c, 1, 1, h, d);
		}
		else {
			cin >> b;
			cout << querySum(b, b, 1, 1, h) << '\n';
		}
	}
	return 0;
}