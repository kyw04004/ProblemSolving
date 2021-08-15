#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int h = 1, n, m, Max, arr[100005];
vector<pair<int,int>> seg;
void update(int idx, int val) {
	idx += h - 1;
	seg[idx].first = val;
	seg[idx].second = idx - h + 1;
	while (idx /= 2) {
		if (seg[idx * 2].first > seg[idx * 2 + 1].first) {
			seg[idx].first = seg[idx * 2 + 1].first;
			seg[idx].second = seg[idx * 2 + 1].second;
		}
		else {
			seg[idx].first = seg[idx * 2].first;
			seg[idx].second = seg[idx * 2].second;
		}
	}
}
int query(int now, int start, int end, int left, int right) {
	if (end < left || right < start) return -1;
	if (left <= start && end <= right) return seg[now].second;
	int mid = (start + end) / 2;
	int l = query(now * 2, start, mid, left, right);
	int r = query(now * 2 + 1, mid + 1, end, left, right);
	if (l == -1) return r;
	if (r == -1) return l;
	return arr[l] > arr[r]? r : l;
}
void go(int left, int right) {
	int idx = query(1, 1, h, left, right);
	Max = max(Max, (right - left + 1) * arr[idx]);
	if(left < idx) go(left, idx - 1);
	if(idx < right)go(idx + 1, right);
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	go(1, n);
	cout << Max;
	return 0;
}