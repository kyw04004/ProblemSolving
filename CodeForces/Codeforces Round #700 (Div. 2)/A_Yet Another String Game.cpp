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
		string str; cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (i % 2 == 0) { // 작게
				if (str[i] == 'a') str[i] = 'b';
				else str[i] = 'a';
			}
			else { // 크게
				if (str[i] == 'z') str[i] = 'y';
				else str[i] = 'z';
			}
		}
		cout << str << '\n';
	}
	return 0;
}