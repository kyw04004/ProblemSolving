#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<stack>
#include<stdio.h>
using namespace std;
typedef long long ll;
int N, K, dp[3005][3005];
int MOD = 1e9 + 7;
int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    dp[1][1] = 0, dp[1][2] = 1, dp[2][2] = 0;
    dp[1][3] = 2, dp[2][3] = 3, dp[3][3] = 2;
    cin >> N >> K;
    for (int i = 4; i <= N; i++)
        for (int j = 1; j <= i; j++) {
            if (j == 1) dp[j][i] = (dp[j][i - 1] + 1 + dp[i - 1][i - 1]) % MOD;
            else dp[j][i] = (dp[j - 1][i - 1] + (2 * (dp[i - 2][i - 2] + 1)) % MOD) % MOD;
        }
    cout << dp[K][N];
    return 0;
}
