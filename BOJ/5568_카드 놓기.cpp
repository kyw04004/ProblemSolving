#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
int n, k, input[11], chk[11], ans;
map<string, int> m;
void go(string str, int select) {
	if (select == k) {
		if (m[str] == 0) m[str] = 1, ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (chk[i] == 0) {
			chk[i] = 1;
			go(str + to_string(input[i]), select + 1);
			chk[i] = 0;
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> input[i];
	go("", 0);
	cout << ans;
	return 0;
}