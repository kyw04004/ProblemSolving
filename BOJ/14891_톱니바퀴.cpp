#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
string state[5];
int K, chk[5][5], sum;
void chkstart() {
	for (int i = 1; i <= 3; i++) {
		if (state[i][2] == state[i + 1][6]) chk[i][i + 1] = chk[i + 1][i] = 1;
		else chk[i][i + 1] = chk[i + 1][i] = -1;
	}
}
void rotate(int n, int d) {
	if (d == 1) {
		char temp = state[n][7];
		for (int i = 7; i >= 1; i--)
			state[n][i] = state[n][i - 1];
		state[n][0] = temp;
	}
	else {
		char temp = state[n][0];
		for (int i = 0; i <= 6; i++)
			state[n][i] = state[n][i + 1];
		state[n][7] = temp;
	}
}
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	for (int i = 1; i <= 4; i++)
		cin >> state[i];
	cin >> K;
	for (int i = 1; i <= K; i++) {
		int num, dir;
		cin >> num >> dir;
		chkstart();
		rotate(num, dir);
		int d = dir;
		for (int j = num; j >= 2; j--) { // 왼쪽으로 가면서 회전
			if (chk[j][j - 1] == 1) break;
			else {
				d *= -1;
				rotate(j - 1, d);
			}
		}
		d = dir;
		for (int j = num; j <= 3; j++) { // 오른쪽으로 가면서 회전
			if (chk[j][j + 1] == 1) break;
			else {
				d *= -1;
				rotate(j + 1, d);
			}
		}
	}
	for (int i = 1; i <= 4; i++)
		if (state[i][0] == '1') sum += (1 << (i - 1));
	cout << sum;
	return 0;
}