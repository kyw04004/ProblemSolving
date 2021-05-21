#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
string str1, str2;
set<vector<int>> s;
int ans = 0;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> str1 >> str2;

	for (int i = 0; i < str1.size(); i++) { //시작 위치
		vector<int> v;
		v.resize(27);
		for (int j = i; j < str1.size(); j++) {
			v[str1[j] - 'a']++;
			s.insert(v);
		}
	}

	for (int i = 0; i < str2.size(); i++) { //시작 위치
		vector<int> v;
		v.resize(27);
		for (int j = i; j < str2.size(); j++) {
			v[str2[j] - 'a']++;
			if (s.count(v)) ans = max(ans, j - i + 1);
		}
	}

	cout << ans;
	return 0;
}