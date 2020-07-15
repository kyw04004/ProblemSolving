#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string a, b, ans;
pair<int,string> dp[42][42];
int main()
{
	cin >> a >> b;
	int ai = a.size();
	int bi = b.size();
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j].first = dp[i - 1][j - 1].first + 1;
				dp[i][j].second = dp[i - 1][j - 1].second + a[i - 1];
			}
			else {
				if (dp[i][j - 1].first > dp[i - 1][j].first) {
					dp[i][j].first = dp[i][j - 1].first;
					dp[i][j].second = dp[i][j - 1].second;
				}
				else {
					dp[i][j].first = dp[i-1][j].first;
					dp[i][j].second = dp[i-1][j].second;
				}
			}
		}
	}
	cout << dp[ai][bi].second;
	return 0;
}