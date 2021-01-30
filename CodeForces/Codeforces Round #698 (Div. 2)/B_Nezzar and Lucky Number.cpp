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
		int q, d; cin >> q >> d;
		int arr[10005], com[15];
		for (int i = 1; i <= q; i++) cin >> arr[i];
		for (int i = 1; i <= 10; i++) com[i] = d * i;
		for (int i = 1; i <= q; i++) {
			int chk = 0;
			int n = arr[i];
			if (n >=  10*d) {
				cout << "YES" << '\n';
				continue;
			}
			if (n % 10 == d) {
				cout << "YES" << '\n';
				continue;
			}
			for (int j = 1; j <= 10; j++) {
				int val = n - com[j];
				if (val < 0) continue;
				if (val == 0 || val % 10 == 0) {
					chk = 1;
					break;
				}
			}
			if (chk) cout << "YES" << '\n';
			else cout << "NO" << "\n";
		}
	}
	return 0;
}