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
		if (n < 3) {
			cout << "NO" << '\n';
			continue;
		}
		if (n % 2 == 1) {
			cout << "YES" << '\n';
			continue;
		}
		while (n % 2 == 0) {
			n /= 2;
		}
		if (n == 1) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
	return 0;
}