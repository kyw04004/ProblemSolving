#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n, m, cnt;
struct Trie {
	bool End;
	Trie* childTrie[27];
	Trie() {
		End = false;
		for (int i = 0; i < 26; i++) childTrie[i] = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (childTrie[i])
				delete childTrie[i];
	}
	void insert(const char* word) {
		if (*word == '\0') {
			End = true; return;
		}
		int next = *word - 'a';
		if (!childTrie[next]) childTrie[next] = new Trie;
		childTrie[next]->insert(word + 1);
	}
	bool find(const char* word) {
		if (*word == '\0') return End;
		int next = *word - 'a';
		if (!childTrie[next]) return false;
		return childTrie[next]->find(word + 1);
	}
};
int main() {
	char word[501];
	cin >> n >> m;
	Trie* trie = new Trie;
	for (int i = 0; i < n; i++) {
		cin >> word;
		trie->insert(word);
	}
	for (int i = 0; i < m; i++) {
		cin >> word;
		if (trie->find(word)) cnt++;
	}
	cout << cnt;
	delete trie;
	return 0;
}