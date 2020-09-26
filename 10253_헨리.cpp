#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
ll t, a, b, ans;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		ans = b;
		ll index = 1;
		while (a != 1) {
			index++;
			ll left = index, right = 2e9;
			while (left <= right) {
				ll mid = (left + right) / 2;
				if (a*mid >= b) right = mid - 1;
				else left = mid + 1;
			}
			index = left;
			ll com1 = b, com2 = index;
			com1 *= index, com2 *= b;
			ll bun = gcd(b, index);
			com1 /= bun;
			ll c = b;
			ll d = index;
			b *= (com1 / c);
			a *= (com1 / c);
			a -= (com1 / d);
			ll m = gcd(a, b);
			a /= m, b /= m;
			ans = b;
		}
		cout << ans << "\n";
	}
	return 0;
}