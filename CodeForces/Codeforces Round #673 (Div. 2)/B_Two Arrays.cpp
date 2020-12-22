#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
ll t, n, T,com;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		com = 0;
		cin >> n >> T;
		for (int i = 0; i < n; i++) {
			ll x; cin >> x;
			x *= 2;
			if (x < T) cout << 0 << ' ';
			if (x > T) cout << 1 << ' ';
			if (x == T) {
				cout << com << ' ';
				com = !com;
			}
		}
		cout << '\n';
	}
	return 0;
}