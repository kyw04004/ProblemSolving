#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
ll t, n, arr[200005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n);
		ll ans = 0;
		for (int i = n-1; i >= 0 ; i--) {
			if ((n-i) % 2 == 1 && arr[i] % 2 == 0) ans += arr[i];
			if ((n-i) % 2 == 0 && arr[i] % 2 == 1) ans -= arr[i];
		}
		if (ans > 0) cout << "Alice" << '\n';
		else if (ans == 0) cout << "Tie" << '\n';
		else cout << "Bob" << '\n';
	}
	return 0;
}