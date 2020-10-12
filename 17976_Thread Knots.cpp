#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int n;
vector<pair<ll, ll>> v;
vector<ll> knot;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x, l;
		cin >> x >> l;
		v.push_back({ x,l });
	}
	sort(v.begin(), v.end());
	ll left = 0, right = 2e9;
	while (left <= right) {
		ll mid = (left + right) / 2;
		knot.clear();
		knot.push_back({ v[0].first });
		int ok = 1;
		for (int i = 0; i < n - 1; i++) {
			if ((v[i + 1].first - knot[i]) >= mid)
				knot.push_back({ v[i + 1].first });
			else {
				if ((v[i + 1].first + v[i + 1].second) < (knot[i] + mid)) {
					ok = 0;
					break;
				}
				else knot.push_back({ knot[i] + mid });
			}
		}
		if (ok) left = mid + 1;
		else right = mid - 1;
	}
	cout << right;
	return 0;
}