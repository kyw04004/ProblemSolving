#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int t, w, h, n;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> w >> h >> n;
		int wcnt = 1, hcnt = 1;
		while (w % 2 == 0) {
			w /= 2;
			wcnt *= 2;
		}
		while (h % 2 == 0) {
			h /= 2;
			hcnt *= 2;
		}
		if (wcnt * hcnt >= n) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
