#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int t;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		int open = 0, close = 0, question = 0, ans = 0;
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(') open++;
			else if (str[i] == ')') close++;
			else question++;
			if (close > open + question) {
				ans = 1;
				break;
			}
		}
		if (str[str.size() - 1] == '(') ans = 1;
		if (str.size() % 2 == 1) ans = 1;
		if (ans) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
	return 0;
}