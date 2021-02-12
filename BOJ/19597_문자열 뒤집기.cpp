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
int t, n, End;
string str[155], rstr[155];
vector<int> ans;
void go(int index, vector<int> com) {
	if (End) return;
	if (index == n - 1) {
		End = 1;
		ans.clear();
		ans = com;
		return;
	}
	if (com.back() == 0) {
		if (str[index] < str[index + 1]) {
			com.push_back(0);
			go(index + 1, com);
			com.pop_back();
		}
		if (str[index] < rstr[index + 1]) {
			com.push_back(1);
			go(index + 1, com);
			com.pop_back();
		}
	}
	if (com.back() == 1) {
		if (rstr[index] < str[index + 1]) {
			com.push_back(0);
			go(index + 1, com);
			com.pop_back();
		}
		if (rstr[index] < rstr[index + 1]) {
			com.push_back(1);
			go(index + 1, com);
			com.pop_back();
		}
	}
	return;
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> str[i];
		for (int i = 0; i < n; i++) {
			string s;
			for (int j = str[i].size() - 1; j >= 0; j--)
				s += str[i][j];
			rstr[i] = s;
		}
		End = 0;
		vector<int> v;
		v.push_back(0);
		go(0, v);
		v.pop_back();
		v.push_back(1);
		go(0, v);
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
		cout << '\n';
	}
	return 0;
}