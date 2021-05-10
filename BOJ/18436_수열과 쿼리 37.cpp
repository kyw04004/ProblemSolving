#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int h = 1, n, m;
vector<pair<int, int>> seg; // ¦Ȧ
void update(int idx, int val) {
	idx += h - 1;
	if (val % 2 == 0) {
		seg[idx].first = 1;
		seg[idx].second = 0;
	}
	else {
		seg[idx].first = 0;
		seg[idx].second = 1;
	}
	while (idx /= 2) {
		seg[idx].first = seg[idx * 2].first + seg[idx * 2 + 1].first;
		seg[idx].second = seg[idx * 2].second + seg[idx * 2 + 1].second;
	}
}
int query(int num, int now, int start, int end, int left, int right) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return num==2 ?seg[now].first : seg[now].second;
	int mid = (start + end) / 2;
	return query(num, now * 2, start, mid, left, right) + query(num, now * 2 + 1, mid + 1, end, left, right);
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
		int num;
		cin >> num;
		update(i, num);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else cout << query(a, 1, 1, h, b, c) << '\n';
	}
	return 0;
}