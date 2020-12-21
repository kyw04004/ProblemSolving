#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
ll t, n;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		while (1) {
			int chk = 1;
			vector<ll> v;
			ll com = n;
			while (com) {
				if (com % 10) v.push_back(com % 10);
				com /= 10;
			}
			for (int i = 0; i < v.size(); i++) {
				if (n%v[i]) {
					n++;
					chk = 0;
					break;
				}
			}
			if (chk) break;
		}
		cout << n << '\n';
	}
	return 0;
}