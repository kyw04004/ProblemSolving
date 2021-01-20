#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
using namespace std;
int solution(string s) {
	int answer = s.size();
	for (int i = 1; i <= s.size() / 2; i++) {
		int len = s.size();
		int ok = 0;
		for (int j = 0; j < s.size(); j += i) {
			for (int k = j; k <= (j + i - 1); k++) {
				if (k + i >= s.size()) {
					ok = 0;
					break;
				}
				if (s[k] == s[k + i]) {
					if (k == (j + i - 1)) {
						if (ok == 0) len += 1;
						if (ok == 8) len += 1;
						if (ok == 98) len += 1;
						if (ok == 998) len += 1;
						ok += 1;
						len -= i;
					}
				}
				else {
					ok = 0;
					break;
				}
			}
		}
		if (answer > len) answer = len;
	}
	return answer;
}