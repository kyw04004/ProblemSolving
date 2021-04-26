#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		deque <int> dq;
		bool Error = false;
		int n;
		string command, arrstr;
		cin >> command;
		cin >> n;
		cin >> arrstr;
		int num = 0;
		for (int i = 0; i < arrstr.size(); i++) {
			if (arrstr[i] == '[') continue;
			if (arrstr[i] == ',' || arrstr[i] == ']') {
				if(num > 0) dq.push_back(num);
				num = 0;
			}
			else num *= 10, num += arrstr[i] - '0';
		}
		int rcnt = 0;
		for (int i = 0; i < command.size(); i++) {
			if (command[i] == 'R') rcnt++;
			else {
				if (dq.empty()) {
					Error = true;
					break;
				}
				else {
					if (rcnt % 2 == 0) dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		if (Error == true) cout << "error\n";
		else {
			if (rcnt % 2 == 0) {
				cout << '[';
				while (!dq.empty()) {
					cout << dq.front();
					if (dq.size() > 1) cout << ',';
					dq.pop_front();
				}
				cout << "]\n";
			}
			else {
				cout << '[';
				while (!dq.empty()) {
					cout << dq.back();
					if (dq.size() > 1) cout << ',';
					dq.pop_back();
				}
				cout << "]\n";
			}
		}
	}
	return 0;
}