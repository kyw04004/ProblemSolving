#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, ans;
string str;
vector<int> pstr;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> str;
	int state = -1;
	int step = 0;
	for (int i = 0; i < M; i++) {
		if (state == -1) {
			if (str[i] == 'O') continue;
			else {
				state = 1;
				continue;
			}
		}
		if (state == 1) {
			if (str[i] == 'O') state = 0;
			else if (step) pstr.push_back(step), step = 0;
		}
		else {
			if (str[i] == 'I') state = 1, step++;
			else {
				if (step) pstr.push_back(step), step = 0;
				state = -1;
			}
		}
	}
	if (step) pstr.push_back(step);
	for (int i = 0; i < pstr.size(); i++)
		if (pstr[i] >= N) ans += (pstr[i] - N + 1);
	cout << ans;
	return 0;
}