#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string str[6];
	string ans[3];
	for (int i = 0; i < 6; i++)
		cin >> str[i];
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 6; k++) {
				if (i == j || j == k || k == i) continue;
				ans[0] = str[i], ans[1] = str[j], ans[2] = str[k];
				int chk[6] = { 0, }, cnt=0;
				for (int a = 0; a < 3; a++)
					for (int b = 0; b < 6; b++)
						if (!chk[b] && ans[a] == str[b]) chk[b]=1,cnt++, b = 6;
				for (int a = 0; a < 3; a++)
					for (int b = 0; b < 6; b++)
						if (!chk[b]&&ans[0][a] == str[b][0] && ans[1][a] == str[b][1] && ans[2][a] == str[b][2])
							cnt++, chk[b] = 1, b = 6;
				if (cnt == 6) {
					for (int i = 0; i < 3; i++)
						cout << ans[i] << "\n";
					return 0;
				}
			}
	cout << "0";
	return 0;
}