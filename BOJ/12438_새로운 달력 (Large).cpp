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
	int T; cin >> T;
	for (int t = 1; t <= T;t++) {
		ll month, md, wd, ans = 0;
		ll mod = 0;
        ll ishare, ashare;
		cin >> month >> md >> wd;
		for (ll i = 1; i <= month; i++) {
			ll imd = md + mod;
			ans += (imd/wd);
			if (imd % wd) ans += 1;
			mod = (imd % wd);
            if(mod==0) {
                ishare =i;
                ashare = ans;
                break;
            }
		}
        ans = ashare * (month/ishare);
        month %= ishare;
        for (ll i = 1; i <= month; i++) {
			ll imd = md + mod;
			ans += (imd/wd);
			if (imd % wd) ans += 1;
			mod = (imd % wd);
		}
		cout << "Case #"<< t << ": "<< ans << "\n";
	}
	return 0;
}
