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
		map<string, int> m;
		int n, ans = 1, cnt = 0, arr[35] = {};
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str1, str2; cin >> str1 >> str2;
			if (m[str2] == 0) m[str2] = ++cnt;
			arr[m[str2]]++;
		}
		for (int i = 1; i <= cnt; i++) ans *= (arr[i] + 1);
		cout << ans - 1 << '\n';
	}
	return 0;
}