#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string str, com[1001];
	cin >> str;
	for (int i = 0; i < str.size(); i++)
		com[i] = str.substr(i);
	sort(com, com + str.size());
	for (int i = 0; i < str.size(); i++)
		cout << com[i] << '\n';
	return 0;
}