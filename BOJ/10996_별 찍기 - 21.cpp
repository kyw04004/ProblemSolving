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
	string str1, str2;
	for (int i = 1; i <= n; i+=2) {
		if(i==1) str1 += '*';
		else  str1 += " *";
	}
	for (int i = 2; i <= n; i += 2)
		str2 += " *";
	if (n == 1) cout << str1;
	else {
		for (int i = 1; i <= n; i++) {
			cout << str1 << '\n';
			cout << str2 << '\n';
		}
	}
	return 0;
}