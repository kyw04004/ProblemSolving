#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
int t, n, ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		cout << "9";
		int val = 8;
		n -= 1;
		while (n--) {
			if (val == 10) val = 0;
			cout << val;
			val++;
		}
		cout << '\n';
	}
	return 0;
}