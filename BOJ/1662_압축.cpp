#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <stack>
using namespace std;
typedef long long ll;
stack<char> s;
int alpha[26], save, ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string compression;
	cin >> compression;
	for (int i = 0; i < compression.size(); i++) {
		if (compression[i] != ')') s.push(compression[i]);
		else {
			int cnt = 0;
			while (s.top() != '(') {
				if (0 <= s.top() - 'A' &&  s.top() - 'A'  <= 25) cnt += alpha[s.top() - 'A'];
				else cnt++;
				s.pop();
			}
			s.pop();
			int R = s.top() - '0';
			s.pop();
			cnt *= R;
			alpha[save] = cnt;
			s.push('A' + save);
			save++;
		}
	}
	while (!s.empty()) {
		if (0 <= s.top() - 'A' &&  s.top() - 'A' <= 25) ans += alpha[s.top() - 'A'];
		else ans++;
		s.pop();
	}
	cout << ans;
	return 0;
}