#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string str, answer = "";
	cin >> str;
	answer += str[0];
	for (int i = 1; i < str.size(); i++)
		if (str[i] == '-') answer += str[i + 1];
	cout << answer;
	return 0;
}