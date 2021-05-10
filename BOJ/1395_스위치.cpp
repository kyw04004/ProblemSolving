#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n, m, h = 1;
typedef long long ll;
vector<ll> seg;
vector<ll> lazy;
void propagation(int node, int L, int R) {
	if (lazy[node] % 2 == 1) {
		seg[node] = abs(R - L + 1 - seg[node]);
		if (R != L) {
			lazy[node * 2] += 1;
			lazy[node * 2 + 1] += 1;
		}
	}
	lazy[node] = 0;
}
void queryLazy(int L, int R, int node, int S, int E, ll val) {
	propagation(node, S, E);
	if (R < S || E < L) return;
	if (L <= S && E <= R) {
		seg[node] = abs(E - S + 1 - seg[node]);
		if (S != E) {
			lazy[node * 2] += 1;
			lazy[node * 2 + 1] += 1;
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
	cin >> n >> m;
	while (n > h) h *= 2;
	seg.resize(h * 2);
	lazy.resize(h * 2);
	for (int i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 0) 
			queryLazy(b, c, 1, 1, h, 1);
		else
			cout << querySum(b, c, 1, 1, h) << '\n';
	}
	return 0;
}