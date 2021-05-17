#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
using namespace std;
typedef long long ll;
map<string, int> m;
int ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		string com = "";
		com +=str[i];
		if (m[com] == 0) ans++, m[com] = 1;
		for (int j = i + 1; j < str.size(); j++) {
			com += str[j];
			if (m[com] == 0) ans ++, m[com] = 1;
		}
	}
	cout << ans;
	return 0;
}