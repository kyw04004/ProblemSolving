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
using namespace std;
typedef long long ll;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while (1) {
		int n, ans = 0, com = 0, count = 0;;
		cin >> n;
		if (n == 0) break;
		string str;
		getline(cin, str);
		getline(cin, str);
		map<char, int> m;
		int st = 0, en = -1;
		for (int i = 0; i < str.size(); i++) {
			com++;
			en++;
			if (!(m[str[i]] >= 1)) {
				m[str[i]] = 1;
				count++;
				while (count > n) {
					com--;
					m[str[st]]--;
					if(!m[str[st]]) count--;
					st++;
				}
			}
			else m[str[i]]++;
			ans = max(ans, com);
		}
		cout << ans << '\n';
	}
	return 0;
}