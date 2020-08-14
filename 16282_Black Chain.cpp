#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n;
int main() {
	cin >> n;
	for (ll i = 1;; i++) {
		ll sum = i;
		ll x = 1;
		for (ll j = 1; j <= i+1; j++) {
			sum += (i + 1)*x;
			x *= 2;
		}
		if (n <= sum) {
			cout << i;
			return 0;
		}
	}
	return 0;
}