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
using namespace std;
typedef long long ll;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll r, c, ans = 0;
	ll top = 1, right = 3, back = 5;
	cin >> r >> c;
	for (ll i = 1; i <= r; i++) {
		ll com, column = c;
		ans += top;
		column--;
		if (column > 4) {
			ans += 14 * (column / 4);
			column %= 4;
		}
		for (ll j = 1; j <= column; j++) {
			if (i % 2 == 1) {
				com = abs(7 - right);
				ans += com;
				right = top;
				top = com;
			}
			else {
				com = right;
				ans += right;
				right = abs(7 - top);
				top = com;
			}
		}
		com = back;
		back = abs(7 - top);
		top = com;
	}
	cout << ans;
	return 0;
}