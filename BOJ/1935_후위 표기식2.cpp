#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
int n, alpha[26];
double two, one;
string str;
stack<double> s;
void setting() {
	two = s.top();
	s.pop();
	one = s.top();
	s.pop();
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		alpha[i] = num;
	}
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '*') {
			setting();
			s.push(one * two);
		}
		else if (c == '+') {
			setting();
			s.push(one + two);
		}
		else if (c == '-') {
			setting();
			s.push(one - two);
		}
		else if (c == '/') {
			setting();
			s.push(one / two);
		}
		else s.push(alpha[c - 'A']);
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top();
	return 0;
}