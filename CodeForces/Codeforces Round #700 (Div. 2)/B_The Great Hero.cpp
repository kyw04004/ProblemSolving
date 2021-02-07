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
pair<ll, ll> m[100005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		ll A, B, N;
		cin >> A >> B >> N;
		for (int i = 0; i < N; i++) cin >> m[i].first;
		for (int i = 0; i < N; i++) cin >> m[i].second;
		sort(m, m + N);
		for (int i = 0; i < N; i++) {
			ll M = ((m[i].second - 1) / A) + 1;
			B -= (M * m[i].first);
		}
		B += m[N - 1].first;
		if (B >= 1) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}