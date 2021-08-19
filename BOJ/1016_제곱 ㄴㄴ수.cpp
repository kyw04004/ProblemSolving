#include <iostream>
#include <vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
map<ll, int> m;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll S, E, ans;
	cin >> S >> E;
	ans = E - S + 1;
	for (ll i = 2; i * i <= E; i++) {
		for (ll j = i * i; j <= E; j += i * i) {
			if (m[j]) continue;
			if (S <= j && j <= E) {
				m[j] = 1;
				ans--;
			}
			else {
				ll q = S / j;
				j *= q;
				if(S == j && !m[j]){
					m[j] = 1;
					ans--;
				}
			}
		}
	}
	cout << ans;
	return 0;
}

