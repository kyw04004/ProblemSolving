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
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n-1; j++) cout << ' ';
		for (int j = 1; j <= 2*(i-1)+1; j++) cout << '*';
		cout << "\n";
	}
	for (int i = n-1; i >=1; i--) {
		for (int j = i; j <= n - 1; j++) cout << ' ';
		for (int j = 1; j <= 2 * (i - 1) + 1; j++) cout << '*';
		cout << "\n";
	}
	return 0;
}