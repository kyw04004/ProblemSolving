#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
int n, arr[500005], h = 1, orderedArr[500005];
map<int, int> ran;
vector<int> seg;
void update(int now, int val) {
	now += h - 1;
	seg[now] = val;
	while (now /= 2)
		seg[now] = seg[now * 2] + seg[now * 2 + 1];
}
int query(int now, int s, int e, int left, int right) {
	if (e < left || right < s) return 0;
	if (left <= s && e <= right) return seg[now];
	int mid = (s + e) / 2;
	return query(now * 2, s, mid, left, right) + query(now * 2 + 1, mid + 1, e, left, right);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		orderedArr[i] = arr[i];
	}
	sort(orderedArr, orderedArr + n);
	for (int i = 0; i < n; i++) ran[orderedArr[i]] = n - i;
	for (int i = 0; i < n; i++) {
		int rank = ran[arr[i]];
		update(rank, 1);
		cout << query(1, 1,h, 1,rank) << '\n';
	}
	return 0;
}