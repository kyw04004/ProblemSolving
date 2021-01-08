#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
int n, m;
vector<pair<ll, ll>> intervals;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		intervals.push_back({ a,b });
	}
	sort(intervals.begin(), intervals.end());
	ll left = 1, right = 1e18;
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		int idx = 0, cnt = 1;
		ll now = intervals[idx].first;
		while (idx < m && cnt < n) {
			if ((now + mid) <= intervals[idx].second) {
				cnt++;
				now += mid;
			}
			else {
				while (1) {
					idx++;
					if (idx >= m) break;
					if (now + mid < intervals[idx].first) {
						now = intervals[idx].first;
						cnt++;
						break;
					}
					else if ((now + mid) <= intervals[idx].second) {
						now += mid;
						cnt++;
						break;
					}
				}
			}
		}
		if (cnt < n) right = mid - 1;
		else {
			left = mid + 1;
			ans = max(ans, mid);
		}
	}
	cout << right;
	return 0;
}