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
		int x, y; cin >> x >> y;
		int dif = y - x;
		int n = 0;
		while (1) {
			n++;
			int val = n * (n + 1) - dif;
			if (val >= 0) {
				if (val < n) cout << n * 2 << '\n';
				else cout << n * 2 - 1 << '\n';
				break;
			}
		}
	}
	return 0;
}