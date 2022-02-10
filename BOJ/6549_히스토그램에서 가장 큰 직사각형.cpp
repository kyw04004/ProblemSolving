#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
int n, h;
ll ans;
vector<pair<int,int>> seg;
void update(int idx, int val) {
	idx += h - 1;
	seg[idx] = { val, idx - h + 1 };
	while (idx /= 2) {
		if (seg[idx * 2].first > seg[idx * 2 + 1].first)
			seg[idx] = seg[idx * 2 + 1];
		else seg[idx] = seg[idx * 2];
	}
}
pair<int,int> query(int now, int s, int e, int left, int right) {
	if (e < left || right < s) return { -1,-1 };
	if (left <= s && e <= right) return seg[now];
	int mid = (s + e) / 2;
	pair<int,int> leftQ = query(now * 2, s, mid, left, right);
	pair<int,int> rightQ = query(now * 2 + 1, mid + 1, e, left, right);
	if (leftQ.first == -1) return rightQ;
	else if (rightQ.first == -1) return leftQ;
	else {
		if (leftQ.first < rightQ.first) return leftQ;
		else return rightQ;
	}
}
void go(int s, int e) {
	pair<int,int> q = query(1, 1, h, s, e);
	ll len = (1LL * (e - s + 1)) * (1LL * q.first);
	ans = max(ans, len);
	if (s <= q.second - 1) go(s, q.second - 1);
	if (q.second + 1 <= e) go(q.second + 1, e);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		cin >> n;
		if (n == 0) break;
		h = 1, ans = 0;
		while (h < n) h *= 2;
		seg.clear();
		seg.resize(h * 2);
		for (int i = 0; i < h * 2; i++) seg[i] = { 1e9,1e9 };
		for (int i = 1; i <= n; i++) {
			int num; cin >> num;
			update(i, num);
		}
		go(1, n);
		cout << ans << '\n';
	}
	return 0;
}