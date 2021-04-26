#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(char a, char b) {
	return a > b;
}
int main() {
	string str;
	int sum = 0;
	bool zero = false;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0') zero = true;
		sum += str[i] - '0';
	}
	if (str.size() < 2 || sum % 3 != 0) zero = false;
	if (zero == false) cout << -1;
	else {
		sort(str.begin(), str.end(), compare);
		cout << str;
	}
	return 0;
}