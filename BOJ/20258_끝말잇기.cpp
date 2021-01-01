#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int n, ans = 1;
string str[101];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> str[i];
	for (int i = 0; i < n; i++) {
		int len = str[i].size();
		for (int j = 0; j < len; j++)
			if (str[i][j] != str[i][len - 1 - j]) ans = 0, i = n, j = len;
	}
	if (ans) {
		for (int i = 0; i < n - 1; i++)
			if (str[i][0] != str[i + 1][0]) ans = 0;
		if (ans) cout << 1;
		else cout << 0;
	}
	else cout << 0;
	return 0;
}