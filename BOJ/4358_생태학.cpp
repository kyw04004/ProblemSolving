#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct Trie {
	bool End;
	Trie* childTrie[100];
	Trie() {
		End = false;
		for (int i = 0; i < 100; i++) childTrie[i] = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 100; i++)
			if (childTrie[i])
				delete childTrie[i];
	}
	void insert(const char* word) {
		if (*word == '\0') {
			End = true; return;
		}
		int next = *word - 32;
		if (!childTrie[next]) childTrie[next] = new Trie;
		childTrie[next]->insert(word + 1);
	}
	bool find(const char* word) {
		if (*word == '\0') return End;
		int next = *word - 32;
		if (!childTrie[next]) return false;
		return childTrie[next]->find(word + 1);
	}
};
int main() {
	int n = 0;
	char word[31], com[31];
	pair<string, double> ans[10001];
	vector<string> v;
	Trie* trie = new Trie;
	while (scanf("%[^\n]%*c", word) != -1) {
		string str(word); v.push_back(str);
	}
	sort(v.begin(), v.end());
	double len = v.size();
	for (int i = 0; i < len; i++) {
		strcpy(com, v[i].c_str());
		if (!trie->find(com)) {
			trie->insert(com);
			ans[++n] = { v[i], 1.0 };
		}
		else ans[n].second+=1.0;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i].first;
		printf(" %0.4lf\n", 100.0 * ans[i].second / len);
	}
	delete trie;
	return 0;
}