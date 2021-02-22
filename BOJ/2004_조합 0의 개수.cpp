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
ll count(ll num, ll searchnum) {
	ll cnt = 0;
	for (ll i = searchnum; i <= num; i *= searchnum)
		cnt += (num / i);
	return cnt;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n, m; cin >> n >> m;
	ll twocount = count(n,2) - count(n - m,2) - count(m,2);
	ll fivecount = count(n,5) - count(n - m,5) - count(m,5);
	cout << min(twocount, fivecount);
	return 0;
}