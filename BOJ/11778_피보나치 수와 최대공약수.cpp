#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
typedef unsigned long long ll;
const ll MOD = 1000000007;
ll n, m;
vector<vector<ll>> v, vv;
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
vector<vector<ll>> fibonacci(ll n) {
	if (n == 0) return  { { 1,0 }, { 0,1 } };
	if (n == 1) return  { { 1,1 }, { 1,0 } };
	vector<vector<ll>> val = fibonacci(n / 2);
	v[0][0] = (((val[0][0] * val[0][0]) % MOD) + (val[0][1] * val[1][0] % MOD)) % MOD;
	v[0][1] = (((val[0][0] * val[0][1]) % MOD) + (val[0][1] * val[1][1] % MOD)) % MOD;
	v[1][0] = (((val[1][0] * val[0][0]) % MOD) + (val[1][1] * val[1][0] % MOD)) % MOD;
	v[1][1] = (((val[1][0] * val[0][1]) % MOD) + (val[1][1] * val[1][1] % MOD)) % MOD;
	vv[0][0] = (v[0][0] + v[1][0]) % MOD;
	vv[0][1] = (v[0][1] + v[1][1]) % MOD;
	vv[1][0] = (v[0][0]) % MOD;
	vv[1][1] = (v[0][1]) % MOD;
	if (n % 2 == 0) return v;
	else return vv;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	v = { { 0,0 }, { 0,0 } };
	vv = { { 0,0 }, { 0,0 } };
	cin >> n >> m;
	ll g = gcd(n, m);
	vector<vector<ll>> a = fibonacci(g - 1);
	cout << a[0][0];
	return 0;
}