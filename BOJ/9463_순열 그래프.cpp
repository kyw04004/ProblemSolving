#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<stdio.h>
using namespace std;
typedef long long ll;
ll T, n, h, arr[100005], cnt, input[100005];
vector<ll> seg;
void update(int idx, ll val) {
	idx += h - 1;
	seg[idx] = val;
	while (idx /= 2)
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
}
ll query(int now, int start, int end, int left, int right) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return seg[now];
	int mid = (start + end) / 2;
	return query(now * 2, start, mid, left, right) + query(now * 2 + 1, mid + 1, end, left, right);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> n;
		cnt = 0, h = 1;
		while (h < n) h *= 2;
		seg.clear();
		seg.resize(h * 2);
		for (int i = 1; i <= n; i++) {
			ll val; cin >> val;
			arr[val] = i;
		}
		for (int i = 1; i <= n; i++) {
			ll val; cin >> val;
			input[i] = arr[val];
		}

		for (int i = 1; i <= n; i++) {
			ll com = input[i];
			cnt += query(1, 1, h, com + 1, n);
			update(input[i], 1);
		}
		cout << cnt << '\n';
	}
	return 0;
}