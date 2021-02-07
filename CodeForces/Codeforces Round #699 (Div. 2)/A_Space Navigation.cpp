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
		int dx, dy; cin >> dx >> dy;
		string str; cin >> str;
		int x = 0, y = 0;
		int R = 0, L = 0, U = 0, D = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'R') R++, x += 1;
			if (str[i] == 'L') L++, x -= 1;
			if (str[i] == 'U') U++, y += 1;
			if (str[i] == 'D') D++, y -= 1;
		}
		int chk = 1;
		if (x > dx) {
			if (R < (x - dx)) chk = 0;
		}
		else if (x < dx) {
			if (L < (dx - x)) chk = 0;
		}
		if (y > dy) {
			if (U < (y - dy)) chk = 0;
		}
		else if (y < dy) {
			if (D < (dy - y)) chk = 0;
		}
		if (chk) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}