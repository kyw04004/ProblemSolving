#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
ll n, m, presents[300005];
ll pos[300005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll t; cin >> t;
	while (t--) {
		ll sum = 0;
		cin >> n >> m;
		memset(pos, 0, sizeof(pos));
		for (int i = 1; i <= n; i++) {
			int x; cin >> x;
			pos[i]++, pos[x]++;
		}
		for (int i = 1; i <= m; i++) cin >> presents[i];
		int index = 1;
		while (n) {
			if (n >= pos[index]) {
				sum += (presents[index] * pos[index]);
				n -= pos[index];
			}
			else {
				sum += (presents[index] * n);
				n = 0;
			}
			index++;
		}
		cout << sum << '\n';
	}
	return 0;
}