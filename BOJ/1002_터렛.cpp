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
		double x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		double d1 = (double)sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		double d2 = r1 + r2;
		if (x1 == x2 && y1 == y2) {
			if (r1 == r2) cout << "-1\n";
			else cout << "0\n";
		}
		else if (d1 > d2) cout << "0\n";
		else if (d1 == d2) cout << "1\n";
		else {
			if ((d1 + (double)min(r1, r2)) < (double)max(r1, r2)) cout << "0\n";
			else if((d1 + (double)min(r1,r2)) == (double)max(r1,r2)) cout << "1\n";
			else cout << "2\n";
		}
	}
	return 0;
}