#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map <string, int> m;
bool solution(vector<string> phone_book) {
	for (int i = 0; i < phone_book.size(); i++)
		m[phone_book[i]] = 1;
	for (int i = 0; i < phone_book.size(); i++) {
		for (int j = 0; j < phone_book[i].size() - 1; j++) {
			string com = phone_book[i].substr(0, j + 1);
			if (m[com]) return false;
		}
	}
	return true;
}