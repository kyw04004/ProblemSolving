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
string T, P;
vector<int> ans;
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
void KMP(string text, string pattern) {
	int j = 0;
	vector<int> pi = getPi(pattern);
	for (int i = 0; i < text.size(); i++) {
		while (j > 0 && text[i] != pattern[j])
			j = pi[j - 1];
		if (text[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				ans.push_back(i - pattern.size() +2);
				j = pi[j];
			}
			else j++;
		}
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin.clear();
	getline(cin, T);
	cin.clear();
	getline(cin, P);
	KMP(T, P);
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}