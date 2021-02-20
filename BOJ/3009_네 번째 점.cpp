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
	int x = 0, y = 0;
	for (int i = 0; i < 3; i++) {
		int a, b; cin >> a >> b;
		x ^= a, y ^= b;
	}
	cout << x << ' ' << y;
	return 0;
}