#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
typedef long long ll;
struct Trie {
	bool finish;
	Trie* child[10];
	Trie() {
		fill(child, child + 10, nullptr);
		finish = false;
	}
	~Trie() {
		for (int i = 0; i < 10; i++)
			if (child[i]) delete child[i];
	}
	void insert(const char* key) {
		if (*key == NULL) {
			finish = true;
			return;
		}
		else {
			int next = *key - '0';
			if (child[next] == NULL) child[next] = new Trie;
			child[next]->insert(key + 1);
		}
	}
	bool exist(const char* key) {
		if (*key == NULL) return false;
		if (finish) return true;
		int next = *key - '0';
		if (child[next] == NULL) return false;
		return child[next]->exist(key + 1);
	}
};
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) {
		int c = 1;
		int n; cin >> n;
		char input[10005][11];
		Trie* trie = new Trie;
		for (int i = 0; i < n; i++) {
			cin >> input[i];
			trie->insert(input[i]);
		}
		for (int i = 0; i < n; i++)
			if (trie->exist(input[i])) c = 0;
		delete trie;
		if (c) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}