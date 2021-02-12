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
int Min;
void go(int a, int b, int cnt) {
	if (cnt > Min) return;
	if (a == 0) {
		Min = min(Min, cnt);
		return;
	}
	if (b > 1) go(a / b, b, cnt + 1);
	go(a, b + 1, cnt + 1);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		Min = 2e9;
		go(a, b, 0);
		cout << Min << '\n';
	}
	return 0;
}