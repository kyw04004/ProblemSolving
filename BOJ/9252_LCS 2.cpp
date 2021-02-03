//Longest common Subsequence
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
#include<stack>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
string a, b;
pair<int,string> dp[1005][1005];
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	int ai = a.size();
	int bi = b.size();
	for (int i = 1; i <= a.size(); i++)
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j].first = dp[i - 1][j - 1].first + 1;
				dp[i][j].second = dp[i - 1][j - 1].second + a[i-1];
			}
			else {
				if (dp[i][j - 1] < dp[i - 1][j]) {
					dp[i][j].first = dp[i - 1][j].first;
					dp[i][j].second = dp[i - 1][j].second;
				}
				else {
					dp[i][j].first = dp[i][j-1].first;
					dp[i][j].second = dp[i][j-1].second;
				}
			}
		}
	cout << dp[ai][bi].first << '\n';
	cout << dp[ai][bi].second;
	return 0;
}