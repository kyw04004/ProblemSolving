#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	string str[51], answer="";
	cin >> n;
	for (int i = 0; i < n; i++) cin >> str[i];
	int len = str[0].size();
	for (int i = 0; i < len; i++) {
		char com = str[0][i];
		bool possible = true;
		for (int j = 1; j < n; j++)
			if (com != str[j][i]) possible = false;
		if (possible == true) answer += com;
		else answer += '?';
	}
	cout << answer;
	return 0;
}