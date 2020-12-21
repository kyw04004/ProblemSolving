#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll n, x, sum, dp[1000001];
int main() {
	cin >> n >> x;
	dp[0] = 1;
	for (int i = 1; i <= 1000000; i++)
		dp[i] = ((x * dp[i - 1])%1000000007);
	for (int i = 0; i <= n; i++) {
		ll a, b;
		cin >> a >> b;
		sum += ((a * dp[b]) % 1000000007);
		sum %= 1000000007;
	}
	cout << sum << "\n";
 	return 0;
}