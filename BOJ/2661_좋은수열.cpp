#include <iostream>
#include <algorithm>
using namespace std;
int N;
string ans;
bool success;
void go(string str, int idx) {
	if (success) return;
	if (idx == N + 1) {
		ans = str;
		success = true;
		return;
	}
	for (int j = 1; j <= 3; j++) {
		bool possible = true;
		for (int k = 1; k <= (idx / 2); k++) {
			int idx = str.size();
			string sub1 = str.substr(idx - (2 * k) + 1, k);
			string sub2 = str.substr(idx - k + 1);
			sub2 += (j + '0');
			if (sub1 == sub2) {
				possible = false;
				break;
			}
		}
		if (possible) {
			str.push_back(j + '0');
			go(str, idx + 1);
			str.pop_back();
		}
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N;
	go("", 1);
	cout << ans;
	return 0;
}