#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
typedef long long ll;
ll h, n, dp[35][35], s, e;
int main()
{
	cin >> h >> n;
	s = min(h, n);
	e = max(h, n);
	for (int i = s; i <= e; i++) dp[s][i] = 1;
	for (int i = s+1; i <= e; i++)
		for (int j = i; j <= e; j++)
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	cout << dp[e][e];
	return 0;
}