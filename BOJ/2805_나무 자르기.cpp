#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n, m, h[1000005], ans;
bool possible(int len) {
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		sum += max(0 * 1LL, h[i] - len);
	if (sum >= m) return true;
	else return false;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	ll left = 0, right = 1e9;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (possible(mid)) {
			left = mid + 1;
			ans = mid;
		}
		else right = mid - 1;
	}
	cout << ans;
	return 0;
}