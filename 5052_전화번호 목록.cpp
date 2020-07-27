#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
bool isConsistent = true;
struct Trie {
	bool isWord, existChild;
	Trie* childTrie[10];
	Trie() {
		isWord = false;
		existChild = false;
		for (int i = 0; i < 10; i++) childTrie[i] = nullptr;
	}
	~Trie() {
		for (int i = 0; i < 10; i++)
			if (childTrie[i])
				delete childTrie[i];
	}
	void insert(char* word) {
		if (*word == '\0') isWord = true;
		else {
			int next = *word - '0';
			if (!childTrie[next]) childTrie[next] = new Trie;
			existChild = true;
			childTrie[next]->insert(word + 1);
		}
		if (isWord && existChild) isConsistent = false;
	}
};
int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		isConsistent = true;
		Trie* trie = new Trie;
		cin >> n;
		for (int j = 0; j < n; j++) {
			char word[11];
			cin >> word;
			trie->insert(word);
		}
		if (isConsistent) cout << "YES\n";
		else cout << "NO\n";
		delete trie;
	}
}