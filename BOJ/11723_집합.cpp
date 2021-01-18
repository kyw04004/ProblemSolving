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
	int M; cin >> M;
	int chk[21] = { 0, };
	while (M--) {
		string str;
		int X;
		cin >> str;
		if (str == "add") {
			cin >> X;
			chk[X] = 1;
		}
		if (str == "remove") {
			cin >> X;
			chk[X] = 0;
		}
		if (str == "check") {
			cin >> X;
			if (chk[X]) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		if (str == "toggle") {
			cin >> X;
			chk[X] = !chk[X];
		}
		if (str == "all") for (int i = 1; i <= 20; i++) chk[i] = 1;
		if (str == "empty") for (int i = 1; i <= 20; i++) chk[i] = 0;
	}
	return 0;
}