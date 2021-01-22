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
vector <int> getPi(string pattern) {
	int m = pattern.size();
	int j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			pi[i] = ++j;
	}
	return pi;
}
string chameleon(string T) {
	vector<int> pi = getPi(T);
	int maxlen = pi[pi.size() - 1];
	if (maxlen == 0) return "-1";
	string pattern = T.substr(0, maxlen);
	for (int i = 1; i < T.size()-1; i++)
		if (pi[i] == maxlen) return pattern;
	pi = getPi(pattern);
	maxlen = pi[pi.size() - 1];
	if (maxlen == 0) return "-1";
	return T.substr(0, maxlen);
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string T;
	cin >> T;
	cout << chameleon(T);
	return 0;
}