#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
ll n, x;
vector<pair<ll, ll>> v;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll t; cin >> t;
	while (t--) {
		ll sum = 0;
		cin >> n >> x;
		v.clear();
		for (int i = 1; i <= n; i++) {
			ll val; cin >> val;
			v.push_back({ val,1 });
		}
		ll c = 1;
		while (c) {
			int len = v.size();
			for (int i = len - n; i < len; i++) {
				if (v[i].first % x == 0) v.push_back({ v[i].first / x , v[i].second + 1 });
				else {
					c = 0;
					break;
				}
			}
		}
		for (int i = 0; i < v.size(); i++)
			sum += v[i].first * (ll)pow(x, v[i].second - 1);
		cout << sum << '\n';
	}
	return 0;
}