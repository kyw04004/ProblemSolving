#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef long long ll;
int main() {
	int n, arr[1001] = { 0, }, dp[1001] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= 1000; i++) 
		for (int j = 1; j <= i; j++) 
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
	cout << dp[n];
	return 0;
}