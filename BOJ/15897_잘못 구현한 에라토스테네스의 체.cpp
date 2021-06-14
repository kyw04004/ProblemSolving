#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
ll n, cnt, last;
map<ll,ll> chk;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (ll i = 1; i <= ceil(sqrt(n)); i++) {
		ll a = (n - 1) / i + 1;
		if(!chk[i]) cnt += a, chk[i] = 1;
		if (!chk[a]) cnt += i, chk[a] = 1;
		if (last == 0) last = a;
		else cnt += i * (last - a - 1), last = a;
	}
	cout << cnt;
	return 0;
}