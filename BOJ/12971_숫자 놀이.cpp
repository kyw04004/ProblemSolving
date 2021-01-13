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
using namespace std;
typedef long long ll;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll X1, X2, X3, P1, P2, P3;
	cin >> P1 >> P2 >> P3 >> X1 >> X2 >> X3;
	for (ll i = 1; i <= P1*P2*P3; i++) {
		if (i%P1 == X1 && i%P2 == X2 && i%P3 == X3) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}