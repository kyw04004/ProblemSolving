#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll N, K, D, ans;
struct element {
	ll a, b, c;
};
vector<element> v;
ll calcu(ll num) {
	ll cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		ll s = v[i].a, e = v[i].b, c = v[i].c;
		if (num < s) continue;
		if (num < e) e = num;
		cnt += (e - s) / c + 1;
	}
	return cnt;
}
int main() {
	cin >> N >> K >> D;
	for (int i = 0; i < K; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		v.push_back({a,b,c});
	}
	ll left = 1, right = N;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (calcu(mid) >= D) {
			ans = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << ans;
	return 0;
}