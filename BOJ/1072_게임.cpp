#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll x, y, ans = 2e9;
bool possible(ll nx, ll ny) {
	ll now = (y * 100) / x;
	ll next = (ny * 100) / nx;
	if (next > now) return true;
	else return false;
}
int main() {
	cin >> x >> y;
	ll left = 0, right = 1e9;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (possible(x + mid, y + mid)) {
			right = mid - 1;
			ans = mid;
		}
		else left = mid + 1;
	}
	if (ans == 2e9) cout << -1;
	else cout << ans;
	return 0;
}