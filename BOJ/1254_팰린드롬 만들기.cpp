#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string str;
int ans;
bool palin(string s) { // Max 1000
	bool can = true;
	int len = s.size();
	for (int i = 0; i < len / 2; i++)
		if (s[i] != s[len - 1 - i]) can = false;
	return can;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> str;
	if (palin(str)) cout << str.size();
	else {
		for (int i = 0; i < str.size(); i++) {
			string com = "";
			for (int j = i; j >= 0; j--) com += str[j];
			if (palin(str + com)) {
				ans = str.size() + i + 1;
				break;
			}
		}
		cout << ans;
	}
	return 0;
}