#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string str, word;
int ans, strLen, wordLen;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	getline(cin, str);
	getline(cin, word);
	strLen = str.size();
	wordLen = word.size();
	for (int i = 0; i <= strLen - wordLen;) {
		bool can = true;
		for (int j = i; j < i + wordLen; j++)
			if (str[j] != word[j - i]) {
				can = false;
				break;
			}
		if (!can) {
			i++;
			continue;
		}
		else ans++, i += wordLen;
	}
	cout << ans;
	return 0;
}