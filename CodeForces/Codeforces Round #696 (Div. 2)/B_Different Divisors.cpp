#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		ll d; cin >> d;
		if (d == 1) {
			cout << 6 << '\n';
			continue;
		}
		ll one, two;
		ll st = 1 + d;
		if (st % 2 == 0) st++;
		for (ll i = st;; i += 2) {
			int chk = 1;
			for (ll j = 2; j < i; j++) {
				if (i%j == 0) {
					chk = 0;
					break;
				}
			}
			if (chk) {
				one = i;
				break;
			}
		}
		st = one + d;
		if (st % 2 == 0) st++;
		for (ll i = st;; i += 2) {
			int chk = 1;
			for (ll j = 2; j < i; j++) {
				if (i%j == 0) {
					chk = 0;
					break;
				}
			}
			if (chk) {
				two = i;
				break;
			}
		}
		cout << one * two << '\n';
	}
	return 0;
}