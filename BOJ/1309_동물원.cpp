#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
#include<stack>
#include<cmath>
using namespace std;
int dp[100001], N;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    dp[0] = 1, dp[1] = 3;
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] * 2 + dp[i - 2];
        dp[i] %= 9901;
    }
    cout << dp[N];
    return 0;
}