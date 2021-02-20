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
int arr[100005], chk[100005];
bool Prime(int num) {
	if (num == 1) return false;
	else if (num == 2) return true;
	for (int i = 2; i < num; i++)
		if (num % i == 0) return false;
	return true;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 10000; i++) {
		if (chk[i]) continue;
		if (Prime(i)) {
			arr[i] = 1;
			for (int j = i; j <= 10000; j+=i)
				chk[j] = 1;
		}
	}
	int t; cin >> t;
	while (t--) {
		int a, b;
		int n; cin >> n;
		if (arr[n - 2]) a = 2, b = n - 2;
		for (int i = 3; i <= (n / 2) ; i += 2) {
			if (!arr[i] || !arr[n-i]) continue;
			a = i, b = n - i;
		}
		cout << a << ' ' << b << '\n';
	}
	return 0;
}