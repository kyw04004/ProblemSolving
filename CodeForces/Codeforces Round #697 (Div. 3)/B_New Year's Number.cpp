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
		ll n; cin >> n;
		int chk = 0;
		for (ll i = 0; i <= 500; i++)
			for (ll j = 0; j <= 500; j++) {
				if (i == 0 && j == 0) continue;
				if (n % (2020 * i + 2021 * j) == 0) {
					chk = 1;
					i = 1000, j = 1000;
				}
			}
		if (chk) cout << "YES" << '\n';
		else  cout << "NO" << '\n';
	}
	return 0;
}