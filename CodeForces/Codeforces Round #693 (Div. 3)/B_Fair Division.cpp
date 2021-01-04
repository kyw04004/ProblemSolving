#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
int t, n, one, two;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		one = 0, two = 0;
		for (int i = 1; i <= n; i++) {
			int val; cin >> val;
			if (val == 1) one++;
			else two++;
		}
		if (one % 2 == 1) cout << "NO" << '\n';
		else if (two % 2 == 0) cout << "YES" << '\n';
		else if (one > two) cout << "YES" << '\n';
		else {
			if (one == 0) cout << "NO" << '\n';
			else cout << "YES" << '\n';
		}
	}
	return 0;
}