#include<iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, dp[1000005];
int main(void) {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000000;
	cin >> n;
	if (n == 0) cout << "0\n";
	else if (n > 0) cout << "1\n";
	else {
		if(n % 2 ==0) cout << "-1\n";
		else cout << "1\n";
	}
	cout << dp[abs(n)];
	return 0;
}