#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string a, b, ans;
int dp[1005][1005];
int main() {
	cin >> a >> b;
	int ai = a.size();
	int bi = b.size();
	for (int i = 1; i <= a.size(); i++) 
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				if (dp[i][j - 1] > dp[i - 1][j]) dp[i][j] = dp[i][j - 1];
				else dp[i][j] = dp[i - 1][j];
			}
		}
	cout << dp[ai][bi];
	return 0;
}