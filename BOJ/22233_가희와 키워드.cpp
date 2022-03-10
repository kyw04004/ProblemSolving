#include<iostream>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
#include<unordered_set>
using namespace std;
typedef unsigned long long ll;
unordered_set<string> m;
int N, M, ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		m.insert(str);
	}
	ans = N;
	for (int i = 0; i < M; i++) {
		string str; cin >> str;
		string com = "";
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == ',') {
				if (m.count(com)) ans--, m.erase(com);
				com = "";
			}
			else com += str[j];
		}
		if (m.count(com)) ans--, m.erase(com);
		cout << ans << '\n';
	}
	return 0;
}