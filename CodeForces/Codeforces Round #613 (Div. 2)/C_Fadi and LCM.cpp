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
ll n;
ll GCD(ll a, ll b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}
bool LCM(ll a, ll b) {
	ll c = GCD(a, b);
	if (a*b%c==0 && a*b / c == n) return true;
	else return false;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	ll a = 1, b = n;
	ll len = floor(sqrt(n));
	for (ll i = 1; i <= len; i++) {
		if (n%i == 0 && LCM(i,n/i)) {
			a = max(a, i);
			b = min(b, n / i);
		}
	}
	cout << a << ' ' << b;
	return 0;
}