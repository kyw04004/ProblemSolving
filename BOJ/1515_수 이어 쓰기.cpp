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
string str;
ll ans, suc;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> str;
	for (ll i = 0; i < str.size(); i += suc) {
		ll num = str[i] - '0';
		for (ll j = ans + 1;; j++) {
			stack<ll> st;
			ll com = j;
			suc = 0;
			while (com > 0) {
				st.push(com % 10);
				com /= 10;
			}
			while (!st.empty()) {
				if (st.top() == num) {
					suc++;
					ans = j;
					num = str[i + suc] - '0';
				}
				st.pop();
			}
			if (suc) break;
		}
	}
	cout << ans;
	return 0;
}