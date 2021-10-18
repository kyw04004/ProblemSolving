#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string str, ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	getline(cin, str);
	bool open = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') continue;
		if (str[i] == '>') {
			open = false;
			continue;
		}
		else if (str[i] == '<') {
			open = true;
			continue;
		}
		if (open) continue;
		string com = "";
		int idx = i;
		while (idx < str.size() && str[idx] != ' ' && str[idx] != '<') {
			com += str[idx];
			idx++;
		}
		idx--;
		for (int j = 0; j <= (idx - i) / 2 ; j++)
			swap(str[i+j], str[idx - j]);
		i = idx;
	}
	cout << str;
	return 0;
}