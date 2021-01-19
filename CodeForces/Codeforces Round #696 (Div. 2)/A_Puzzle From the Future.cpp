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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string b; cin >> b;
		string a = "1";
		for (int i = 1; i < n; i++) {
			if (a[i - 1] == '1' && b[i - 1] == '1') {
				if (b[i] == '1') a += '0';
				else a += '1';
			}
			if (a[i - 1] == '0' && b[i - 1] == '1') {
				if (b[i] == '1') a += '1';
				else a += '0';
			}
			if (a[i - 1] == '1' && b[i - 1] == '0') {
				if (b[i] == '1') a += '1';
				else a += '0';
			}
			if (a[i - 1] == '0' && b[i - 1] == '0') {
				a += '1';
			}
		}
		cout << a << '\n';
	}
	return 0;
}