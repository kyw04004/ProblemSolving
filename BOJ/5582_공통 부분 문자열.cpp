//Longest common Substring
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
int dp[4005][4005], ans;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	int ai = a.size();
	int bi = b.size();
	for (int i = 1; i <= a.size(); i++)
		for (int j = 1; j <= b.size(); j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = 0;
			ans = max(ans, dp[i][j]);
		}
	cout << ans;
	return 0;
}