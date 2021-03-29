#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int n, m, len, dif, _mod, _cnt;
string str[11], ans;
vector<vector<int>> seq;
vector<int> com;
void go(int index, int depth) {
	if (com.size() == _mod) {
		seq.push_back(com);
		return;
	}
	for (int i = index + 1; i <= n - 1; i++) {
		com.push_back(i);
		go(i, depth + 1);
		com.pop_back();
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 200; i++) ans += 'z';
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
		len += str[i].size();
	}
	dif = m - len;
	_mod = dif % (n - 1); // 추가해야할 갯수
	_cnt = dif / (n - 1); // 최소 갯수
	go(0, 0);
	for (int k = 0; k < seq.size(); k++) {
		string com;
		for (int i = 1; i <= n; i++) {
			com += str[i];
			if (i == n) continue;
			for (int j = 1; j <= _cnt; j++) com += '_';
			for (int j = 0; j < seq[k].size(); j++)
				if (i == seq[k][j]) com += '_';
		}
		ans = min(ans, com);
	}
	cout << ans;
	return 0;
}