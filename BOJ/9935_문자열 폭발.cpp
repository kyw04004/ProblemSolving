#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;
stack <char> ansS, output;
int main() {
	stack <int> s;
	string str, exploStr;
	cin >> str >> exploStr;
	for (int i = 0; i < str.size(); i++) {
		ansS.push(str[i]);
		if (ansS.top() == exploStr.back()) {
			stack <char> saveS;
			bool canExplo = true;
			for (int k = exploStr.size() - 1; k >= 0; k--) {
				if (ansS.empty() || ansS.top() != exploStr[k]) {
					canExplo = false;
					break;
				}
				saveS.push(ansS.top());
				ansS.pop();
			}
			if(canExplo == false)
				while (!saveS.empty()) {
					ansS.push(saveS.top());
					saveS.pop();
				}
		}
	}
	while (!ansS.empty()) {
		output.push(ansS.top());
		ansS.pop();
	}
	if (output.empty()) cout << "FRULA";
	else
		while (!output.empty()) {
			cout << output.top();
			output.pop();
		}
	return 0;
}