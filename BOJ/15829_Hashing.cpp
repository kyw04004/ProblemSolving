#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
using namespace std;
typedef long long ll;
map<int, ll> m;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll L, sum = 0, com=1;
	string str;
	cin >> L >> str;
	for (int i = 0; i < 50; i++) {
		m[i] = com;
		com *= 31;
		com %= 1234567891;
	}
	for (ll i = 0; i < L; i++) {
		sum += (str[i] - 'a' + 1) * m[i];
		sum %= 1234567891;
	}
	cout << sum;
	return 0;
}