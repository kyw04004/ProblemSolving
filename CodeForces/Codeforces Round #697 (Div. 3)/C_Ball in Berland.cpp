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
ll arr[200005], brr[200005];
ll ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		memset(arr, 0, sizeof(arr));
		memset(brr, 0, sizeof(brr));
		ll a, b, k;
		cin >> a >> b >> k;
		ans = k * (k - 1);
		ans /= 2;
		for (ll i = 1; i <= k; i++) {
			int a; cin >> a;
			arr[a]++;
		}
		for (ll i = 1; i <= k; i++) {
			int b; cin >> b;
			brr[b]++;
		}
		for (ll i = 1; i <= a; i++) {
			if (arr[i] > 1) {
				ll m = arr[i] * (arr[i] - 1);
				m /= 2;
				ans -= m;
			}
		}
		for (ll i = 1; i <= b; i++) {
			ll m = brr[i] * (brr[i] - 1);
			m /= 2;
			if (brr[i] > 1) ans -= m;
		}
		cout << ans << '\n';
	}
	
	return 0;
}