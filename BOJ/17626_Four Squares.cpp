#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
int dp[50001], val[230], n;
int main() {
	for (int i = 0; i <= 230; i++) val[i] = i * i;
	for (int i = 1; i <= 50000; i++) dp[i] = i;
	for (int i = 2; i <= 50000; i++) {
		for (int j = 1; val[j] <= i; j++) {
			if (i >= val[j]) dp[i] = min(dp[i], dp[i - val[j]] + 1);
		}
	}
	cin >> n;
	cout << dp[n];
	return 0;
}