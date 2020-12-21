#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
ll t, n, ans[51], chk[10];
void go(ll now, ll com) {
	if (now > 50) return;
	ans[now] = min(ans[now], com);
	for (ll i = 0; i <= 9; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			go(now + i, 10 * com + i);
			chk[i] = 0;
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i <= 50; i++) ans[i] = 2e10;
	go(0, 0);
	while (t--) {
		memset(chk, 0, sizeof(chk));
		cin >> n;
		if (n < 10) cout << n << '\n';
		else if (n > 45) cout << -1 << '\n';
		else cout << ans[n] << '\n';
	}
	return 0;
}